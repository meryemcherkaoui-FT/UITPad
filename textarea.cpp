#include "textarea.h"
#include <QPainter>
#include <QTextBlock>

// --- Constructeur ---
TextArea::TextArea(QWidget *parent) : QPlainTextEdit(parent) {
    lineNumberArea = new LineNumberArea(this);

    // Connexions pour mettre à jour la marge quand on écrit ou bouge
    connect(this, &TextArea::blockCountChanged, this, &TextArea::updateLineNumberAreaWidth);
    connect(this, &TextArea::updateRequest, this, &TextArea::updateLineNumberArea);
    connect(this, &TextArea::cursorPositionChanged, this, &TextArea::highlightCurrentLine);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();

    // Police d'écriture type "Code" (Monospace)
    QFont font("Consolas"); // Essayez "Courier New" si Consolas ne marche pas
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(11);
    setFont(font);

    // Désactive le retour à la ligne automatique (scroll horizontal à la place)
    setLineWrapMode(QPlainTextEdit::NoWrap);
}

// --- Calcul de la largeur de la marge (ex: pour afficher "100", il faut plus de place que "9") ---
int TextArea::lineNumberAreaWidth() {
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    // 10px de padding + la largeur des chiffres
    int space = 10 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
    return space;
}

// --- Mise à jour de la marge gauche de la zone de texte ---
void TextArea::updateLineNumberAreaWidth(int /* newBlockCount */) {
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

// --- Mise à jour de l'affichage de la zone des numéros ---
void TextArea::updateLineNumberArea(const QRect &rect, int dy) {
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

// --- Gestion du redimensionnement de la fenêtre ---
void TextArea::resizeEvent(QResizeEvent *e) {
    QPlainTextEdit::resizeEvent(e);
    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

// --- Surlignage de la ligne active (couleur bleue clair) ---
void TextArea::highlightCurrentLine() {
    QList<QTextEdit::ExtraSelection> extraSelections;
    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        QColor lineColor = QColor(Qt::blue).lighter(190); // Couleur bleu très clair
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }
    setExtraSelections(extraSelections);
}

// --- Dessin des numéros de ligne (C'est ici qu'on peint la marge grise) ---
void TextArea::lineNumberAreaPaintEvent(QPaintEvent *event) {
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), QColor("#D3D3D3")); // Fond GRIS CLAIR

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            // Dessine le numéro aligné à droite
            painter.drawText(0, top, lineNumberArea->width() - 5, fontMetrics().height(),
                             Qt::AlignRight, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
