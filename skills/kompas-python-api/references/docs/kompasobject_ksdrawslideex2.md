# ksDrawSlideEx2 - Отрисовать указанный слайд в заданном окне

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_ksdrawslidefromfile.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksdrawslideex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций [ksDrawSlideEx.](ksdrawslideex.html)

Синтаксис Automation:

long ksDrawSlideEx2(long HWindow, long sldID, VARIANT hInst);

Входные параметры:

HWindow | \- дескриптор окна, в котором нужно отрисовать BITMAP-слайд,  
---|---  
sldID | \- идентификатор BITMAP-слайда в файле ресурсов,  
hInst | \- hInstance библиотеки, в которой расположен слайд.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Слайд должен быть описан в ресурсном файле библиотеки при помощи объекта RCDATA. HINSTANCE библиотеки нужно передать через VARIANT как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [KompasObject::ksDrawSlideEx](kompasobject_ksdrawslideex.html).

Подразделы:

(отсутствуют)
