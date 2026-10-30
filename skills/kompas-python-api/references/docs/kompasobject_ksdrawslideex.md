# ksDrawSlideEx - Отрисовать указанный слайд в заданном окне

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_ksdrawslideex2.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksdrawslide.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksDrawSlideEx](ksdrawslideex.html).

Синтаксис Automation:

long ksDrawSlideEx (long HWindow,

long slideId,

long hInst);

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
slideId | \- идентификатор слайда,  
hInst | \- hInstance текущей библиотеки или NULL, если она одна.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения.  
---|---  
  
Примечание:

Слайд должен быть описан в ресурсном файле библиотеки при помощи объекта RCDATA.

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64. Рекомендуется использовать функцию [KompasObject::ksDrawSlideEx2](kompasobject_ksdrawslideex2.html).

Подразделы:

(отсутствуют)
