# fixedComponent - Состояние фиксации компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - свойства ](kspart_props.html) |  Scroll [ [ [ ](kspart_hidden.html "К следующему разделу")](kspart_props.html "На уровень выше")](kspart_filename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- компонент зафиксирован,  
---|---  
FALSE | \- компонент не зафиксирован.  
  
Синтаксис Automation:

fixedComponent = iPart.fixedComponent | Получить свойство ([* ](1.html))  
---|---  
iPart.fixedComponent = fixedComponent | Установить свойство ([* ](1.html))  
fixedComponent = iPart.GetFixedComponent() | Получить свойство ([**](2.html))  
iPart.SetFixedComponent(fixedComponent) | Установить свойство ([**](2.html))  
  
Примечание:

Если компонент зафиксирован, то нельзя изменить его местоположение.

Подразделы:

(отсутствуют)
