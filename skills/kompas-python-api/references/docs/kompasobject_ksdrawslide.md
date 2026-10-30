# ksDrawSlide - Отрисовать слайд в заданном окне

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_ksdrawslideex.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksdrawbitmapex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [DrawSlide](drawslide.html).

Синтаксис Automation:

long ksDrawSlide (long HWindow, long slideId);

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
slideId | \- идентификатор слайда.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

Слайд должен быть описан в ресурсном файле библиотеки при помощи объекта RCDATA.

Подразделы:

(отсутствуют)
