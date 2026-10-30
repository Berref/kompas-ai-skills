# Attributes - Массив атрибутов документа в виде массива SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - свойства ](ikompasdocument1_props.html) |  Scroll [ [ [ ](ikompasdocument1_author.html "К следующему разделу")](ikompasdocument1_props.html "На уровень выше")](ikompasdocument1_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

Attributes = Object.Attributes( long Key1, long Key2, long Key3, long Key4, double Numb, VARIANT Objects ) | Получить свойство ([* ](1.html))  
---|---  
Attributes = Object.GetAttributes( long Key1, long Key2, long Key3, long Key4, double Numb, VARIANT Objects ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Attributes( long Key1, long Key2, long Key3, long Key4, double Numb, VARIANT Objects, &Attributes ) | Получить свойство  
---|---  
  
Входные параметры:

Key1, Key2, Key3, Key4 | \- ключи атрибута,  
---|---  
Numb | \- уникальный номер типа атрибута,  
Objects | \- массив VT_ARRAY | VT_DISPATCH объектов, атрибуты которых нужно получить, или указатель на объект VT_DISPATCH.  
  
Примечание:

1\. Свойство позволяет получать атрибуты документа. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

3\. Чтобы получить все объекты с заданным атрибутом, надо в качестве параметра Objects передать VARIANT с типом VT_EMPTY

4\. Чтобы получить атрибуты документа, надо в качестве параметра Objects передать указатель на документ (тип VT_DISPATCH).

5\. Чтобы получить все атрибуты объекта, надо в качестве параметра Numb передать 0.

6\. Если в качестве параметра Objects будет передан массив объектов, то вернутся групповые атрибуты для этих объектов.

Подразделы:

(отсутствуют)
