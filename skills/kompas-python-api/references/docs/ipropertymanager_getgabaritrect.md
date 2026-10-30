# GetGabaritRect - Получить габаритный прямоугольник Панели свойств

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - методы ](ipropertymanager_methods.html) |  Scroll [ [ [ ](ipropertymanager_hidetabs.html "К следующему разделу")](ipropertymanager_methods.html "На уровень выше")](ipropertymanager_clearspectoolbar.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymanager.html)

Синтаксис Automation:

void GetGabaritRect (long* left,

long* top,

long* right,

long* bottom);

Синтаксис COM:

HRESULT GetGabaritRect ([out] long* left,

[out] long* top,

[out] long* right,

[out] long* bottom);

Выходные параметры:

left, top | \- координата верхней левой точки,  
---|---  
right, bottom | \- координата нижней правой точки.  
  
Примечание:

Метод позволяет получить габаритный прямоугольник Панели свойств. Точки задаются в относительных координатах окна КОМПАС.

Подразделы:

(отсутствуют)
