# ObjectsByAttr - Массив объектов документа в виде массива SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - свойства ](ikompasdocument1_props.html) |  Scroll [ [ [ ](ikompasdocument1_openversion.html "К следующему разделу")](ikompasdocument1_props.html "На уровень выше")](ikompasdocument1_metadata.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

Attributes = Object.ObjectsByAttr( long Key1, long Key2, long Key3, long Key4, double Numb, VARIANT ObjectType ) | Получить свойство ([* ](1.html))  
---|---  
Attributes = Object.ObjectsByAttr( long Key1, long Key2, long Key3, long Key4, double Numb, VARIANT ObjectType ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectsByAttr( long Key1, long Key2, long Key3, long Key4, double Numb, VARIANT ObjectType, &Attributes ) | Получить свойство  
---|---  
  
Входные параметры:

Key1, Key2, Key3, Key4 | \- ключи атрибута,  
---|---  
Numb | \- уникальный номер типа атрибута,  
ObjectType | \- тип объектов.  
  
Примечание:

1\. Свойство позволяет получать объекты с заданным типом атрибута. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
