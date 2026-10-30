# PartnerIndex - Индекс точки на втором объекте (начинается с 0, у дуги и окружности 0-центр)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_partnersegmentindex.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_partner.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: long

Синтаксис Automation:

PartnerIndex = iObject.PartnerIndex | Получить свойство([* ](1.html))  
---|---  
iObject.PartnerIndex = PartnerIndex | Установить свойство ([* ](1.html))  
PartnerIndex = iObject.GetPartnerIndex() | Получить свойство ([**](2.html))  
iObject.SetPartnerIndex(PartnerIndex) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

PartnerIndex = iObject->get_PartnerIndex() | Получить свойство  
---|---  
iObject->put_PartnerIndex(PartnerIndex) | Установить свойство  
  
Значения свойства:

TRUE | \- описание активно,  
---|---  
FALSE | \- описание неактивно.  
  
Примечание:

Свойство позволяет установить и получить индекс точки на втором графическом объекте, который используется для создания ограничения.

Применяется, например, для ограничения "Совпадение двух точек"(ksCMergePoints).

Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
