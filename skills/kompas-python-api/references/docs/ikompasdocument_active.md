# Active - Активность документа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - свойства ](ikompasdocument_props.html) |  Scroll [ [ [ ](ikompasdocument_changed.html "К следующему разделу")](ikompasdocument_props.html "На уровень выше")](ikompasdocument_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument.html)

Тип данных: BOOL

Синтаксис Automation:

Active = iObject.Active | Получить свойство ([* ](1.html))  
---|---  
iObject.Active = Active | Установить свойство ([* ](1.html))  
Active = iObject.GetActive() | Получить свойство ([**](2.html))  
iObject.SetActive (Active) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Active (&Active) | Получить свойство  
---|---  
iObject->put_Active (Active) | Установить свойство  
  
Примечание:

Позволяет получить активность документа. Установить можно только значение TRUE, т.е. сделать документ активным, если он неактивен. Значение FALSE игнорируется.

Подразделы:

(отсутствуют)
