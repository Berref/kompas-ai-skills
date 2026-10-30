# Leader - Указатель на линию-выноску, заданную по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс ILeaders ](ileaders.html) > [ILeaders - свойства ](ileaders_props.html) |  Scroll [ [ [ ](ileaders_methods.html "К следующему разделу")](ileaders_props.html "На уровень выше")](ileaders_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ileaders.html)

Тип данных: указатель на интерфейс [IBaseLeader](ibaseleader.html)

Синтаксис Automation:

Leader = Object.Leader( Index ) | Получить свойство([* ](1.html))  
---|---  
Leader = Object.GetLeader( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Leader( Index, &Leader ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта \- VT_BSTR - имя объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции, reference объекта и имя объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
