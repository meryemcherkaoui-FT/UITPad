#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    setupStyle();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUi() {
    // 1. Configuration de la fenêtre
    setWindowTitle("CodeMind");
    resize(1024, 768);

    // 2. Widget Central (qui contient tout le reste)
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Pas de marge sur les bords
    mainLayout->setSpacing(0);
    setCentralWidget(centralWidget);

    // 3. Barre de Menu (File, Edition...)
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    menuBar->addMenu("File");
    menuBar->addMenu("Edition");
    menuBar->addMenu("AI");     // Votre fonctionnalité IA
    menuBar->addMenu("Display");

    // 4. Barre d'outils (Toolbar) avec icônes simulées
    QToolBar *toolBar = addToolBar("Main Toolbar");
    toolBar->setMovable(false);

    // Spacer pour pousser les icônes vers la droite (optionnel, selon votre image)
    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacer);

    // Ajout des boutons d'action (Undo, Redo, Theme, Langue)
    toolBar->addAction("↺"); // Undo
    toolBar->addAction("↻"); // Redo
    toolBar->addAction("◐"); // Mode Sombre/Clair
    toolBar->addAction("🌐"); // Langue

    // 5. La Barre d'onglets personnalisée (Design CodeMind)
    // Conteneur noir pour l'onglet
    QWidget *tabBarContainer = new QWidget();
    tabBarContainer->setObjectName("TabBarContainer"); // ID pour le CSS
    tabBarContainer->setFixedHeight(35);

    QHBoxLayout *tabLayout = new QHBoxLayout(tabBarContainer);
    tabLayout->setContentsMargins(0, 0, 0, 0);
    tabLayout->setSpacing(0);

    // L'onglet "Actif" bleu
    QLabel *activeTab = new QLabel("  Code.txt  "); // Espaces pour simuler le padding
    activeTab->setObjectName("ActiveTab");          // ID pour le CSS
    tabLayout->addWidget(activeTab);

    tabLayout->addStretch(); // Remplit le reste de vide
    mainLayout->addWidget(tabBarContainer);

    // 6. Ajout de l'éditeur de texte (TextArea)
    textArea = new TextArea(this);
    // Texte par défaut pour l'exemple
    textArea->setPlainText("Your C++ code goes here\n"
                           "here\n"
                           "\n"
                           "int main() {\n"
                           "    return 0;\n"
                           "}");
    mainLayout->addWidget(textArea);
}

void MainWindow::setupStyle() {
    // C'est ici qu'on donne le look "CodeMind" avec du QSS (similaire à CSS)
    this->setStyleSheet(R"(
        /* Fond général */
        QMainWindow {
            background-color: #FFFFFF;
        }

        /* --- Barre de Menu --- */
        QMenuBar {
            background-color: #FFFFFF;
            color: #333;
            font-family: "Arial";
            font-size: 14px;
            font-weight: bold;
            border-bottom: 2px solid #000;
        }
        QMenuBar::item {
            padding: 8px 15px;
            background: transparent;
        }
        QMenuBar::item:selected {
            background-color: #E0E0E0;
        }

        /* --- Barre d'Outils --- */
        QToolBar {
            background-color: #FFFFFF;
            border-bottom: 1px solid #CCC;
            spacing: 15px;
            padding: 5px;
        }
        QToolButton {
            background: transparent;
            font-size: 18px;
            color: #000;
            font-weight: bold;
            border: none;
        }
        QToolButton:hover {
            background-color: #EEE;
            border-radius: 4px;
        }

        /* --- Onglets --- */
        QWidget#TabBarContainer {
            background-color: #333333; /* Bande noire sous l'onglet */
        }
        QLabel#ActiveTab {
            background-color: #5B8BD9; /* LE BLEU CODEMIND */
            color: white;
            font-family: "Arial";
            font-weight: bold;
            font-size: 13px;
            padding: 0px 25px;
            /* Astuce : forme biseautée simulée par CSS simple ici */
        }

        /* --- Zone de Texte --- */
        QPlainTextEdit {
            background-color: #E0E0E0; /* Gris clair de votre image */
            color: #333333;
            border: none;
            selection-background-color: #A0A0FF;
        }
    )");
}
