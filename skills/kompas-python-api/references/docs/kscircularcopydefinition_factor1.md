# factor1 - Признак полного шага в радиальном направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по концентрической сетке (Интерфейсы ksCircularCopyDefinition, ICopyCircularDefinition) ](kscircularcopydefinition.html) > [ICopyCircularDefinition - свойства ](kscircularcopydefinition_props.html) |  Scroll [ [ [ ](kscircularcopydefinition_factor2.html "К следующему разделу")](kscircularcopydefinition_props.html "На уровень выше")](kscircularcopydefinition_count2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step1](kscircularcopydefinition_step1.html) устанавливает расстояние между крайними элементами массива в радиальном направлении,  
---|---  
FALSE | \- свойство [step1](kscircularcopydefinition_step1.html) устанавливает расстояние между соседними элементами массива в радиальном направлении.  
  
Синтаксис Automation:

factor1 = iCopyCirc.factor1 | Получить свойство([* ](1.html))  
---|---  
iCopyCirc.factor1 = factor1 | Установить свойство ([* ](1.html))  
factor1 = iCopyCirc.GetFactor1() | Получить свойство ([**](2.html))  
iCopyCirc.SetFactor1(factor1) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
