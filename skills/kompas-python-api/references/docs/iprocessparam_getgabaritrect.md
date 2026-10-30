# GetGabaritRect - Получить габаритный прямоугольник Панели свойств

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessParam ](iprocessparam.html) > [IProcessParam - методы ](iprocessparam_methods.html) |  Scroll [ [ [ ](iprocessparam_popprocessname.html "К следующему разделу")](iprocessparam_methods.html "На уровень выше")](iprocessparam_clearspectoolbar.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](iprocessparam.html)

Синтаксис Automation:

void GetGabaritRect( long * left,

long * top,

long * right,

long * bottom );

Синтаксис COM:

HRESULT GetGabaritRect( [out]long * left,

[out]long * top,

[out]long * right,

[out]long * bottom );

Выходные параметры:

left, top | \- координата верхней левой точки,  
---|---  
right, bottom | \- координата нижней правой точки.  
  
Примечание:

Метод позволяет получить габаритный прямоугольник Панели свойств. Точки задаются в относительных координатах окна КОМПАС.

Подразделы:

(отсутствуют)
