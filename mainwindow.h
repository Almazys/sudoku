#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include <QList>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

typedef struct Case {
    int number,ligne,colonne,carre;
} Case;

enum level {easier=0, easy=1, medium=2, hard=3, harder=4, hardcore=5};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionA_pto_triggered();

    void on_actionA_propos_triggered();

    void on_actionQuitter_triggered();

    void on_pushButton_clicked();

    void on_actionEffacer_grille_triggered();

    void on_actionFacile_triggered();

    void on_actionMoyen_triggered();

    void on_actionTr_s_facile_triggered();

    void on_actionDifficile_triggered();

    void on_actionTr_s_difficile_triggered();

    void on_actionHardcore_triggered();

    void on_actionMontrer_solution_triggered();

    void on_actionDonner_un_indice_triggered();

    void updateChrono();

private:
    void newGame(level currentLevel);
    bool check();
    bool check1(std::list<int> lineList);
    bool check2(std::list<int> lineList);
    bool check3(std::list<int> lineList);
    bool compare(std::list<int> cases);
    //void createDialog(QString message);
    void generateGrid();
    int generateNumber(int max);
    void identifyCase(Case *current);
    void hideCase(level currentLevel);
    void lockCases();
    void unlockCases();
    void colorCases();
    void uncolorCases();
    bool isGridFull();

    Ui::MainWindow *ui;
    std::list<QString> solution;

    QTimer *timer;
    int heures,minutes,secondes,hintsLeft;
};

#endif // MAINWINDOW_H
