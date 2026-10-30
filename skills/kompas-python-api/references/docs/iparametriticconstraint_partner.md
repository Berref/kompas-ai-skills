# Partner - Второй объект или массив SAFEARRAY объектов для установки ограничения

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_partnerindex.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_minutes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: VARIANT (VT_ARRAY | VT_DISPATCH) или VT_DISPATCH

Синтаксис Automation:

Partner = iObject.Partner | Получить свойство([* ](1.html))  
---|---  
iObject.Partner = Partner | Установить свойство ([* ](1.html))  
Partner = iObject.GetPartner() | Получить свойство ([**](2.html))  
iObject.SetPartner(Partner) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Partner = iObject->get_Partner() | Получить свойство  
---|---  
iObject->put_Partner(Partner) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить второй объект. SAFEARRAY используется только для ограничения "Ассоциативная связь"(ksCAssociation). Например, для углового размера ассоциативная связь может быть установлена на два отрезка, между которыми установлен размер.

2\. Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
