# InsertDash - Настройка начала блока: вставлять тире

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_insertnull.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_initialposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

InsertDash = iObject.InsertDash | Получить свойство ([* ](1.html))  
---|---  
iObject.InsertDash = InsertDash | Установить свойство ([* ](1.html))  
InsertDash = iObject.GetInsertDash() | Получить свойство ([**](2.html))  
iObject.SetInsertDash( InsertDash ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_InsertDash( &InsertDash ) | Получить свойство  
---|---  
iObject->put_InsertDash( InsertDash ) | Установить свойство  
  
Значения свойства:

TRUE | \- вставлять тире перед числом,  
---|---  
FALSE | \- не вставлять тире перед числом.  
  
Примечание:

Позволяет настроить формат номеров исполнений специфицируемого изделия (номеров исполнений, располагающихся в «шапке» спецификации).

Настройка номеров исполнений имеет смысл только для групповых спецификаций.

Подразделы:

(отсутствуют)
