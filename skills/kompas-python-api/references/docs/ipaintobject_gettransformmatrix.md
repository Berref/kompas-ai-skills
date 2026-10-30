# GetTransformMatrix - Получить коэффициенты для матрицы преобразования координат

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IPaintObject ](ipaintobject.html) > [IPaintObject - методы ](ipaintobject_methods.html) |  Scroll [ [ [ ](ba1711159.html "К следующему разделу")](ipaintobject_methods.html "На уровень выше")](ipaintobject_gethwnd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipaintobject.html)

Синтаксис Automation:

void GetTransformMatrix (double* a11,

double* a12,

double* a13,

double* a14,

double* a21,

double* a22,

double* a23,

double* a24);

Синтаксис COM:

HRESULT GetTransformMatrix ([out]double* a11,

[out]double* a12,

[out]double* a13,

[out]double* a14,

[out]double* a21,

[out]double* a22,

[out]double* a23,

[out]double* a24);

Выходные параметры:

a11, a12, a13, a14, a21, a22, a23, a24 | \- коэффициенты для матрицы преобразования координат.  
---|---  
  
Примечание:

Матрица для преобразования координат mm -> LP:

Xlp = Xmm * a11 + Ymm * a12 + Zmm * a13 + a14;

Ylp = Xmm * a21 + Ymm * a22 + Zmm * a23 + a24;

Подразделы:

(отсутствуют)
