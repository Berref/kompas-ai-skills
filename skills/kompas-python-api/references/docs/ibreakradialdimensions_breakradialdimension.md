# RadialDimension - Радиальный размер c изломом, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс IBreakRadialDimensions ](ibreakradialdimensions.html) > [IBreakRadialDimensions - свойства ](ibreakradialdimensions_props.html) |  Scroll [ [ [ ](ibreakradialdimensions_methods.html "К следующему разделу")](ibreakradialdimensions_props.html "На уровень выше")](ibreakradialdimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreakradialdimensions.html)

Тип данных: указатель на интерфейс радиального размера c изломом [IBreakRadialDimension](ibreakradialdimension.html)

Синтаксис Automation:

BreakRadialDimension = iObject.BreakRadialDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
BreakRadialDimension = iObject.GetBreakRadialDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BreakRadialDimension( Index, &BreakRadialDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс узла.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
