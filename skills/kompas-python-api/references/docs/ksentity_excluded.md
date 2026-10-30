# excluded - Признак включения или выключения из расчета

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [ksEntity - свойства ](ksentity_props.html) |  Scroll [ [ [ ](ksentity_hidden.html "К следующему разделу")](ksentity_props.html "На уровень выше")](ksentity_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentity.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- исключить из расчёта,  
---|---  
FALSE | \- включить в расчёт.  
  
Синтаксис Automation:

excluded = iEntity.excluded | Получить свойство ([* ](1.html))  
---|---  
iEntity.excluded = excluded | Установить свойство ([* ](1.html))  
excluded = iEntity.GetExcluded() | Получить свойство ([**](2.html))  
iEntity.SetExcluded(excluded) | Установить свойство ([**](2.html))  
  
Примечание:

1\. После установки признака Excluded в True исключение объекта из расчета происходит сразу, без вызова Update. Поэтому изменение объектов (и вызов Update) нужно делать до переключения Excluded в True.

2\. Начиная с КОМПАС-3D V12, исключенные из расчета объекты считаются не валидными.

Подразделы:

(отсутствуют)
