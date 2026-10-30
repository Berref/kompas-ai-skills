# Delete - Удалить ограничение

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - методы ](iparametriticconstraint_methods.html) |  Scroll [ [ [ ](idrawingobject1.html "К следующему разделу")](iparametriticconstraint_methods.html "На уровень выше")](iparametriticconstraint_create.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Синтаксис Automation:

BOOL Delete();

Синтаксис COM:

HRESULT Delete([out, retval] VARIANT_BOOL* pVal);

Возвращаемое значение:

TRUE | \- параметрическое ограничение удалено,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод удаляет описание ограничение. Значение свойства [IParametriticConstraint::Valid](iparametriticconstraint_valid.html) становится равным FALSE (ограничение недействительно).

Подразделы:

(отсутствуют)
