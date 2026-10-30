# DisableEmptyBlockString - Режим вывода пустых строк вокруг начала блока

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_disableadditionalblockemptystrings.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_disableemptystring.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

DisableEmptyBlockString = iObject.DisableEmptyBlockString | Получить свойство ([* ](1.html))  
---|---  
iObject.DisableEmptyBlockString = DisableEmptyBlockString | Установить свойство ([* ](1.html))  
DisableEmptyBlockString = iObject.GetDisableEmptyBlockString() | Получить свойство ([**](2.html))  
iObject.SetDisableEmptyBlockString (DisableEmptyBlockString) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DisableEmptyBlockString (&DisableEmptyBlockString) | Получить свойство  
---|---  
iObject->put_DisableEmptyBlockString (DisableEmptyBlockString) | Установить свойство  
  
Значения свойства:

TRUE | \- не показывать пустые строки, обрамляющие название начала блоков спецификации,  
---|---  
FALSE | \- показывать пустые строки, обрамляющие название начала блоков спецификации.  
  
Примечание:

Позволяет включать и отключать показ пустых строк, обрамляющих название начала блоков спецификации.

Подразделы:

(отсутствуют)
