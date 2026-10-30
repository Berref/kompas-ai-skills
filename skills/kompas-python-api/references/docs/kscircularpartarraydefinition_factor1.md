# factor1 - Признак полного шага в радиальном направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по концентрической сетке (Интерфейсы ksCircularPartArrayDefinition, ICircularPartArrayDefinition) ](kscircularpartarraydefinition.html) > [ksCircularPartArrayDefinition - свойства ](kscircularpartarraydefinition_props.html) |  Scroll [ [ [ ](kscircularpartarraydefinition_factor2.html "К следующему разделу")](kscircularpartarraydefinition_props.html "На уровень выше")](kscircularpartarraydefinition_count2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularpartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step1](kscircularpartarraydefinition_count1.html) задает расстояние между крайними в радиальном направлении копиями,  
---|---  
FALSE | \- свойство step1 задает расстояние между соседними в радиальном направлении копиями.  
  
Синтаксис Automation:

factor1 = iArrayCirc.factor1 | Получить свойство([* ](1.html))  
---|---  
iArrayCirc.factor1 = factor1 | Установить свойство ([* ](1.html))  
factor1 = iArrayCirc.GetFactor1() | Получить свойство ([**](2.html))  
iArrayCirc.SetFactor1(factor1) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
