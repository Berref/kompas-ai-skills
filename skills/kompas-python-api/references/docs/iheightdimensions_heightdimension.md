# HeightDimension - Размер высоты, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс IHeightDimensions ](iheightdimensions.html) > [IHeightDimensions - свойства ](iheightdimensions_props.html) |  Scroll [ [ [ ](iheightdimensions_methods.html "К следующему разделу")](iheightdimensions_props.html "На уровень выше")](iheightdimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iheightdimensions.html)

Тип данных: указатель на интерфейс размера высоты [IHeightDimension](iheightdimension.html)

Синтаксис Automation:

HeightDimension = iObject.HeightDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
HeightDimension = iObject.GetHeightDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HeightDimension( Index, &HeightDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
