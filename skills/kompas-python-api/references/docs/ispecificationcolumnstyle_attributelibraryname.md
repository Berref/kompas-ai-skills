# AttributeLibraryName - Имя файла библиотеки типов атрибутов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_calculatesum.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_attributekey4.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

AttributeLibraryName = iObject.AttributeLibraryName | Получить свойство ([* ](1.html))  
---|---  
AttributeLibraryName = iObject.GetAttributeLibraryName() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AttributeLibraryName (&AttributeLibraryName) | Получить свойство  
---|---  
  
Примечание:

1\. Используется только для колонок со значением типа Запись (см. [ValueType](ispecificationcolumnstyle_valuetype.html)).

2\. Структура записи в колонке определяется типом атрибута из библиотеки типов атрибутов.

3\. Для данной колонки можно будет использовать типы атрибутов только из указанной библиотеки

4\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
