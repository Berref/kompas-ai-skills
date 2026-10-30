# DisableEmptyString - Режим вывода пустых строк вокруг заголовка раздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_disableemptyblockstring.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_deletespcobjectondeletegeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

DisableEmptyString = iObject.DisableEmptyString | Получить свойство ([* ](1.html))  
---|---  
iObject.DisableEmptyString = DisableEmptyString | Установить свойство ([* ](1.html))  
DisableEmptyString = iObject.GetDisableEmptyString() | Получить свойство ([**](2.html))  
iObject.SetDisableEmptyString (DisableEmptyString) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DisableEmptyString (&DisableEmptyString) | Получить свойство  
---|---  
iObject->put_DisableEmptyString (DisableEmptyString) | Установить свойство  
  
Значения свойства:

TRUE | \- не показывать пустые строки, обрамляющие название разделов спецификации,  
---|---  
FALSE | \- показывать пустые строки, обрамляющие название разделов спецификации.  
  
Примечание:

Позволяет включать и отключать показ пустых строк, обрамляющих название разделов спецификации.

Подразделы:

(отсутствуют)
