# ksDrawSlideFromFile - Отрисовать слайд в окне из текстового файла, содержащего блок RCDATA

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_kserror.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksdrawslideex2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksDrawSlideFromFile](ksdrawslidefromfile.html).

Синтаксис Automation:

long ksDrawSlideFromFile (long HWindow,

BSTR fileName);

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
fileName | \- полное имя файла.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

Функция предназначена для отладки слайдов. Позволяет просмотреть отредактированный слайд в окне диалога без перетрансляции тестовой библиотеки.

Подразделы:

(отсутствуют)
