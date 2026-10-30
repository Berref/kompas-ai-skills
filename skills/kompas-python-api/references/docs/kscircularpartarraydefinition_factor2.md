# factor2 - Признак полного шага в кольцевом направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по концентрической сетке (Интерфейсы ksCircularPartArrayDefinition, ICircularPartArrayDefinition) ](kscircularpartarraydefinition.html) > [ksCircularPartArrayDefinition - свойства ](kscircularpartarraydefinition_props.html) |  Scroll [ [ [ ](kscircularpartarraydefinition_inverce.html "К следующему разделу")](kscircularpartarraydefinition_props.html "На уровень выше")](kscircularpartarraydefinition_factor1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularpartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step2](kscircularpartarraydefinition_count2.html) задает угол между крайними лучами сетки,  
---|---  
FALSE | \- свойство step2 задает угол между соседними лучами сетки.  
  
Синтаксис Automation:

factor2 = iArrayCirc.factor2 | Получить свойство([* ](1.html))  
---|---  
iArrayCirc.factor2 = factor2 | Установить свойство ([* ](1.html))  
factor2 = iArrayCirc.GetFactor2() | Получить свойство ([**](2.html))  
iArrayCirc.SetFactor2(factor2) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
