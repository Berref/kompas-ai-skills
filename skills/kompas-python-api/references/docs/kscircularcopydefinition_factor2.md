# factor2 - Признак полного шага в кольцевом направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по концентрической сетке (Интерфейсы ksCircularCopyDefinition, ICopyCircularDefinition) ](kscircularcopydefinition.html) > [ICopyCircularDefinition - свойства ](kscircularcopydefinition_props.html) |  Scroll [ [ [ ](kscircularcopydefinition_geomarray.html "К следующему разделу")](kscircularcopydefinition_props.html "На уровень выше")](kscircularcopydefinition_factor1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step2](kscircularcopydefinition_step2.html) устанавливает расстояние между крайними элементами массива в кольцевом направлении,  
---|---  
FALSE | \- свойство step2 устанавливает расстояние между соседними элементами массива в кольцевом направлении.  
  
Синтаксис Automation:

factor2 = iCopyCirc.factor2 | Получить свойство([* ](1.html))  
---|---  
iCopyCirc.factor2 = factor2 | Установить свойство ([* ](1.html))  
factor2 = iCopyCirc.GetFactor2() | Получить свойство ([**](2.html))  
iCopyCirc.SetFactor2(factor2) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
