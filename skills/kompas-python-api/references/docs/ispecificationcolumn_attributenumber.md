# AttributeNumber - Номер типа атрибута

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumn ](ispecificationcolumn.html) > [ISpecificationColumn - свойства ](ispecificationcolumn_props.html) |  Scroll [ [ [ ](ispecificationcolumn_blocknumber.html "К следующему разделу")](ispecificationcolumn_props.html "На уровень выше")](ispecificationcolumn_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumn.html)

Тип данных: double

Синтаксис Automation:

AttributeNumber = iObject.AttributeNumber | Получить свойство ([* ](1.html))  
---|---  
iObject.AttributeNumber = AttributeNumber | Установить свойство ([* ](1.html))  
AttributeNumber = iObject.GetAttributeNumber() | Получить свойство ([**](2.html))  
iObject.SetAttributeNumber( AttributeNumber ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AttributeNumber( &AttributeNumber ) | Получить свойство  
---|---  
iObject->put_AttributeNumber( AttributeNumber ) | Установить свойство  
  
Примечание:

1\. Используется только для колонки с типом значения ksValueTypeRecord [ISpecificationColumn::ValueType](ispecificationcolumn_valuetype.html).

Если требуется просто удалить тип атрибута, то в качестве значения этого свойства надо присвоить 0. В этом случае значение колонки с типом ksValueTypeRecord будет аналогично типу ksValueTypeString.

2\. Изменение этого свойства вступит в силу после вызова метода [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
