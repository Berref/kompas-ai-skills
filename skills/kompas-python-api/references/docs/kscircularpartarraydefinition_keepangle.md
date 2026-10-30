# keepAngle - Признак сохранения угла копий

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по концентрической сетке (Интерфейсы ksCircularPartArrayDefinition, ICircularPartArrayDefinition) ](kscircularpartarraydefinition.html) > [ksCircularPartArrayDefinition - свойства ](kscircularpartarraydefinition_props.html) |  Scroll [ [ [ ](kscircularpartarraydefinition_step1.html "К следующему разделу")](kscircularpartarraydefinition_props.html "На уровень выше")](kscircularpartarraydefinition_inverce.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularpartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- обратное направление,  
---|---  
FALSE | \- прямое направление.  
  
Синтаксис Automation:

keepAngle = iCircularPartArray.keepAngle | Получить свойство([* ](1.html))  
---|---  
iCircularPartArray.keepAngle = keepAngle | Установить свойство ([* ](1.html))  
keepAngle = iCircularPartArray.GetKeepAngle() | Получить свойство ([**](2.html))  
iCircularPartArray.SetKeepAngle( keepAngle ) | Установить свойство ([**](2.html))  
  
Примечание:

Если значение свойства равно TRUE, то необходимо сохранять угол копий.

Подразделы:

(отсутствуют)
