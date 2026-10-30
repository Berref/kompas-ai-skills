# GetCurrentGabarit - Получить текущий габарит документа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IGabaritObject ](igabaritobject.html) > [IGabaritObject - методы ](igabaritobject_methods.html) |  Scroll [ [ [ ](igabaritobject_getgabaritmodifying.html "К следующему разделу")](igabaritobject_methods.html "На уровень выше")](igabaritobject_addgabarit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](igabaritobject.html)

Синтаксис Automation:

void GetCurrentGabarit (long nPage,

double* p1X,

double* p1Y,

double* p1Z,

double* p2X,

double* p2Y,

double* p2Z);

Синтаксис COM:

HRESULT GetCurrentGabarit ([in]long nPage,

[out]double *p1X,

[out]double *p1Y,

[out]double *p1Z,

[out]double *p2X,

[out]double *p2Y,

[out]double *p2Z )

Входные параметры:

nPage | \- номер листа, начиная с единицы.  
---|---  
  
Выходные параметры:

p1X, p1Y, p1Z, p2X, p2Y, p2Z | \- координаты габаритной рамки документа.  
---|---  
  
Примечание:

Метод позволяет получить текущий габарит документа в миллиметрах. Для многолистовых документов можно получить габарит конкретного листа.

Подразделы:

(отсутствуют)
