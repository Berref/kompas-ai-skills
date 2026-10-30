# NominalValue - Значение размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IDimensionText ](idimensiontext.html) > [IDimensionText - свойства ](idimensiontext_props.html) |  Scroll [ [ [ ](idimensiontext_prefix.html "К следующему разделу")](idimensiontext_props.html "На уровень выше")](idimensiontext_nominaltext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimensiontext.html)

Тип данных: double

Синтаксис Automation:

NominalValue = Object.NominalValue | Получить свойство([* ](1.html))  
---|---  
Object.NominalValue = NominalValue | Установить свойство ([* ](1.html))  
NominalValue = Object.GetNominalValue() | Получить свойство ([**](2.html))  
Object.SetNominalValue( NominalValue ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_NominalValue( &NominalValue ) | Получить свойство([* ](1.html))  
---|---  
Object.put_NominalValue( NominalValue ) | Установить свойство ([* ](1.html))  
  
Примечание:

1\. Позволяет получить и установить значение размера.

2\. При изменении свойства выполняются следующие действия:

•формируется текстовое значение номинала [IDimensionText::NominalText](idimensiontext_nominaltext.html);

•у размера снимается признак автоматического определения номинального значения [IDimensionText::AutoNominalValue](idimensiontext_autonominalvalue.html);

Значение размера при этом не изменяется. Значение размера изменяется при изменении параметров размера, например, при изменении расстояния между выносными линиями линейного размера.

Подразделы:

(отсутствуют)
