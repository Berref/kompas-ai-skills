# Интерфейс IParametriticConstraint

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) |  Scroll [ [ [ ](iparametriticconstraint_props.html "К следующему разделу")](bb2391397.html "На уровень выше")](bb2391397.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметрического ограничения.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IParametriticConstraint](iparametriticconstraint.html)

Описание:

Интерфейс позволяет получить доступ к параметрическому ограничению в 2D документе.

Изменение параметров ограничения возможно на этапе создания ограничения. Создать ограничение можно при помощи метода [IDrawingObject1::NewConstraint](idrawingobject1_newconstraint.html).

Если необходимо отредактировать параметрическое ограничение, то его нужно удалить и создать новое с нужными параметрами.

Примечание:

1\. Аналоги интерфейса в API5:

API Экспортных функций:

•Структура параметров: [ConstraintParam](structconstraintparam.html).

Функции:

•[ksSetObjConstraint](kssetobjconstraint.html) \- Установить параметрическое ограничение.

•[ksDestroyObjConstraint](ksdestroyobjconstraint.html) \- Разрушить параметрическое ограничение.

Automation:

•[ksConstraintParam](ksconstraintparam.html) \- Интерфейс параметров для параметрических ограничений.

Методы:

•[ksDocument2D::ksSetObjConstraint](ksdocument2d_kssetobjconstraint.html) \- Установить параметрическое ограничение.

•[ksDocument2D::ksDestroyObjConstraint](ksdocument2d_ksdestroyobjconstraint.html) \- Разрушить параметрическое ограничение.

2\. В API5 нельзя создать или получить ограничения следующих типов:

•Ассоциативная связь.

•Размер с переменной.

•Фиксированный размер.

Подразделы:

[IParametriticConstraint - свойства ](iparametriticconstraint_props.html)

[IParametriticConstraint - методы ](iparametriticconstraint_methods.html)
