# AllSelected - Признак включения или выключения из расчета всех частей тела

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс частей тела (Интерфейсы ksBodyParts, IBodyParts) ](ksbodyparts.html) > [IBodyParts - свойства ](ksbodyparts_props.html) |  Scroll [ [ [ ](ksbodyparts_methods.html "К следующему разделу")](ksbodyparts_props.html "На уровень выше")](ksbodyparts_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodyparts.html)

Тип данных:BOOL.

Значения свойства:

TRUE | \- выбраны все части,  
---|---  
FALSE | \- не все части выбраны.  
  
Синтаксис Automation:

AllSelected = iPart.AllSelected | Получить свойство([* ](1.html))  
---|---  
iPart.AllSelected = AllSelected | Установить свойство ([* ](1.html))  
AllSelected = iPart.GetAllSelected() | Получить свойство ([**](2.html))  
iPart.SetAllSelected(AllSelected ) | Установить свойство ([**](2.html))  
  
Примечание:

Если нужно включить или выключить все части из расчета или узнать, включены ли все части, то для ускорения используется это свойство. Для этой же цели можно анализировать или изменять каждую часть отдельно.

Подразделы:

(отсутствуют)
