# AutoSorted - Автосортировка

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBase3D ](ibase3d.html) > [IBase3D - свойства ](ibase3d_props.html) |  Scroll [ [ [ ](ibase3d_baseplane.html "К следующему разделу")](ibase3d_props.html "На уровень выше")](ibase3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibase3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- включить опцию,  
---|---  
FALSE | \- отключить опцию.  
  
Синтаксис Automation:

AutoSorted = Object.AutoSorted | Получить свойство ([* ](1.html))  
---|---  
Object.AutoSorted = AutoSorted | Установить свойство ([* ](1.html))  
AutoSorted = Object.GetAutoSorted() | Получить свойство ([**](2.html))  
Object.SetAutoSorted( AutoSorted ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AutoSorted( &AutoSorted ) | Получить свойство  
---|---  
Object.put_AutoSorted( AutoSorted ) | Установить свойство  
  
Примечание.

1\. По умолчанию значение свойства равно TRUE.

2\. При отключенной опции доступно редактирование текста 3D базы с помощью свойства [IBase3D::Text](ibase3d_text.html).

Подразделы:

(отсутствуют)
