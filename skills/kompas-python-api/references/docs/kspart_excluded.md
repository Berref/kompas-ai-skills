# excluded - Исключить/включить в расчет деталь

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - свойства ](kspart_props.html) |  Scroll [ [ [ ](kspart_marking.html "К следующему разделу")](kspart_props.html "На уровень выше")](kspart_hidden.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- исключить деталь из расчета,  
---|---  
FALSE | \- включить деталь в расчет.  
  
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
