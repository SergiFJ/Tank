#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();
    
  protected:
    //Pinta el tanc;
    virtual void pintaTanc();

    virtual void pintaCos();

    virtual void pintaCano();

    virtual void pintaRodes();

    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ();

    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ();
 
    // resize - Es cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);  

    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

  private:
    
    void creaBuffersQuadrat();
    
    void carregaShaders();
    
    void modelTransformQuadratCano(glm::vec3 posicio, glm::vec3 escala);

    void modelTransformQuadratRoda(glm::vec3 posicio, glm::vec3 escala,float angle);

    void modelTransformQuadrat(glm::vec3 posicio, glm::vec3 escala);
    
    // program
    QOpenGLShaderProgram *program;
    // attribute locations
    GLuint vertexLoc;
    GLuint colorLoc;

    float angle_cano = 0;
    float movx = 0;
    float angle_rodes = 0;
    // uniform locations
    GLuint TGLoc;

    // VAOs
    GLuint VAOQuadrat;

    // viewport
    GLint ample, alt;    
    
    // colors
    glm::vec3 verd = glm::vec3(0.0,0.6,0.0);
    glm::vec3 negre = glm::vec3(0.0);    
    glm::vec3 gris = glm::vec3(0.5,0.5,0.5);
};
