# InsertNull - Настройка начала блока: вставлять нули перед числом

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_linktype.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_insertdash.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

InsertNull = iObject.InsertNull | Получить свойство ([* ](1.html))  
---|---  
iObject.InsertNull = InsertNull | Установить свойство ([* ](1.html))  
InsertNull = iObject.GetInsertNull() | Получить свойство ([**](2.html))  
iObject.SetInsertNull (InsertNull) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_InsertNull (&InsertNull) | Получить свойство  
---|---  
iObject->put_InsertNull (InsertNull ) | Установить свойство  
  
Значения свойства:

TRUE | \- вставлять нули перед числом,  
---|---  
FALSE | \- не вставлять нули перед числом.  
  
Примечание:

Позволяет настроить формат номеров исполнений специфицируемого изделия (номеров исполнений, располагающихся в «шапке» спецификации).

Настройка номеров исполнений имеет смысл только для групповых спецификаций.

Подразделы:

(отсутствуют)
