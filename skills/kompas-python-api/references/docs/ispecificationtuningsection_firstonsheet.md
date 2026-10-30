# FirstOnSheet - Размещать на новом листе

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuningSection ](ispecificationtuningsection.html) > [ISpecificationTuningSection - свойства ](ispecificationtuningsection_props.html) |  Scroll [ [ [ ](ispecificationtuningsection_independentposition.html "К следующему разделу")](ispecificationtuningsection_props.html "На уровень выше")](ispecificationtuningsection_attachgeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuningsection.html)

Тип данных: BOOL

Синтаксис Automation:

FirstOnSheet = iObject.FirstOnSheet | Получить свойство ([* ](1.html))  
---|---  
FirstOnSheet = iObject.FirstOnSheet | Установить свойство ([* ](1.html))  
FirstOnSheet = iObject.GetFirstOnSheet() | Получить свойство ([**](2.html))  
iObject.SetFirstOnSheet (FirstOnSheet) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FirstOnSheet (&FirstOnSheet) | Получить свойство  
---|---  
iObject->put_FirstOnSheet (FirstOnSheet) | Установить свойство  
  
Значения свойства:

TRUE | \- располагать раздел на новой странице,  
---|---  
FALSE | \- располагать раздел сразу за предыдущим.  
  
Примечание:

Позволяет включать и отключать размещение раздела на новом листе спецификации.

Подразделы:

(отсутствуют)
