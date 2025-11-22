#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <QPlainTextEdit>
#include <QWidget>

// Déclaration anticipée (on dit juste que cette classe va exister)
class LineNumberArea;

// --- 1. On définit TextArea EN PREMIER ---
class TextArea : public QPlainTextEdit {
    Q_OBJECT

public:
    TextArea(QWidget *parent = nullptr);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    QWidget *lineNumberArea;
};

// --- 2. On définit LineNumberArea EN DEUXIÈME ---
// Maintenant, le compilateur sait que TextArea est un QPlainTextEdit (et donc un QWidget)
class LineNumberArea : public QWidget {
public:
    LineNumberArea(TextArea *editor) : QWidget(editor), codeEditor(editor) {}

    QSize sizeHint() const override {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    TextArea *codeEditor;
};

#endif // TEXTAREA_H
