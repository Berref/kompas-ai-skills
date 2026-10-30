# Init - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Выносной элемент (Интерфейс ksRemoteElementParam) ](ksremoteelementparam.html) > [ksRemoteElementParam - методы ](ksremoteelementparam_methods.html) |  Scroll [ [ [ ](ksremoteelementparam_getptext.html "К следующему разделу")](ksremoteelementparam_methods.html "На уровень выше")](ksremoteelementparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksremoteelementparam.html)

Синтаксис Automation:

BOOL Init (long style);

Входной параметр:

(long) style | \- стиль текста.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

1\. Метод обнуляет поля структуры параметров [RemoteElementParam](remoteelementparam.html), которую обслуживает.

2\. Если style == INDICATIN_TEXT_LINE_ARR, то создается динамический массив строк текста TEXT_LINE_ARR. Его структура описывается [TextLineParam](structtextlineparam.html).

3\. Если style == 0, то создается динамический массив указателей на строки символов CHAR_STR_ARR.

Подразделы:

(отсутствуют)
