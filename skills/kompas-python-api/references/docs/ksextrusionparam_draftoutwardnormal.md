# draftOutwardNormal - Признак уклона внутрь в прямом направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Элемент выдавливания (Интерфейсы ksExtrusionParam, IExtrusionParam) ](ksextrusionparam.html) > [IExtrusionParam - свойства ](ksextrusionparam_props.html) |  Scroll [ [ [ ](ksextrusionparam_draftoutwardreverse.html "К следующему разделу")](ksextrusionparam_props.html "На уровень выше")](ksextrusionparam_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksextrusionparam.html)

Тип данных: BOOL

Значения свойства:

FALSE | \- уклон наружу,  
---|---  
TRUE | \- уклон внутрь.  
  
Синтаксис Automation:

draftOutwardNormal = iExtrusionParam.draftOutwardNormal | Получить свойство([* ](1.html))  
---|---  
iExtrusionParam.draftOutwardNormal = draftOutwardNormal | Установить свойство ([* ](1.html))  
draftOutwardNormal = iExtrusionParam.GetDraftOutwardNormal() | Получить свойство ([**](2.html))  
iExtrusionParam.SetDraftOutwardNormal (draftOutwardNormal) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
