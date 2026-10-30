# inverce - Признак направления копирования

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по концентрической сетке (Интерфейсы ksCircularCopyDefinition, ICopyCircularDefinition) ](kscircularcopydefinition.html) > [ICopyCircularDefinition - свойства ](kscircularcopydefinition_props.html) |  Scroll [ [ [ ](kscircularcopydefinition_step1.html "К следующему разделу")](kscircularcopydefinition_props.html "На уровень выше")](kscircularcopydefinition_geomarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- обратное направление,  
---|---  
FALSE | \- прямое направление.  
  
Синтаксис Automation:

inverce = iCopyCirc.inverce | Получить свойство([* ](1.html))  
---|---  
iCopyCirc.inverce = inverce | Установить свойство ([* ](1.html))  
inverce = iCopyCirc.GetInverce() | Получить свойство ([**](2.html))  
iCopyCirc.SetInverce(inverce) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
