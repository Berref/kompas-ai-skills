# FirstOnSheet - Блок размещать с новой страницы

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IAdditionalBlockTuning ](iadditionalblocktuning.html) > [IAdditionalBlockTuning - свойства ](iadditionalblocktuning_props.html) |  Scroll [ [ [ ](iadditionalblocktuning_independentposition.html "К следующему разделу")](iadditionalblocktuning_props.html "На уровень выше")](iadditionalblocktuning_documentname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iadditionalblocktuning.html)

Тип данных: BOOL

Синтаксис Automation:

FirstOnSheet = iObject.FirstOnSheet | Получить свойство ([* ](1.html))  
---|---  
iObject.FirstOnSheet = FirstOnSheet | Установить свойство ([* ](1.html))  
FirstOnSheet = iObject.GetFirstOnSheet() | Получить свойство ([**](2.html))  
iObject.SetFirstOnSheet (FirstOnSheet) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FirstOnSheet (&FirstOnSheet) | Получить свойство  
---|---  
iObject->put_FirstOnSheet (FirstOnSheet) | Установить свойство  
  
Значения свойства:

TRUE | \- располагать блок на новой странице,  
---|---  
FALSE | \- располагать блок сразу за предыдущим.  
  
Примечание:

Позволяет включать и отключать размещение блока на новом листе спецификации.

Подразделы:

(отсутствуют)
