# ActiveDocument - Получить текущий активный документ

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - свойства ](iapplication_props.html) |  Scroll [ [ [ ](iapplication_applicationname.html "К следующему разделу")](iapplication_props.html "На уровень выше")](iapplication_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Тип данных: указатель на интерфейс [IKompasDocument](ikompasdocument.html).

Синтаксис Automation:

ActiveDocument = iObject.ActiveDocument | Получить свойство ([* ](1.html))  
---|---  
iObject.ActiveDocument = ActiveDocument | Установить свойство ([* ](1.html))  
ActiveDocument = iObject.GetActiveDocument() | Получить свойство([**](2.html))  
iObject.SetActiveDocument (ActiveDocument) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ActiveDocument (&ActiveDocument) | Получить свойство  
---|---  
iObject->put_ActiveDocument (ActiveDocument) | Установить свойство  
  
Примечание:

Свойство позволяет получить или установить текущий документ, если ни один документ не открыт.

Подразделы:

(отсутствуют)
