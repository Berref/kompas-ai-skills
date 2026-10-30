# Параметры, определяемые пользователем (Интерфейс ksUserParam)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) |  Scroll [ [ [ ](ksuserparam_props.html "К следующему разделу")](ksdocument2d.html "На уровень выше")](ksltvariant_init.html "К предыдущему разделу")  
---|---  
  
Интерфейс пользовательских параметров.

Примечания:

Указатель на интерфейс можно получить при помощи метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html).

Интерфейс используется для передачи массива пользовательских данных:

1\. Установить/получить массив значений ячеек таблицы атрибутов.

Смотрите: [ksAttributeParam::SetValues](ksattributeparam_setvalues.html), [ksAttributeParam::GetValues](ksattributeparam_getvalues.html).

2\. Установить/получить значение ячейки в таблице атрибута.

Смотрите: [ksAttributeObject::ksSetAttrValue](ksattributeobject_kssetattrvalue.html), [ksAttributeObject::ksSetAttrValue](ksattributeobject_kssetattrvalue.html).

3\. Установить/получить данные строки в таблице атрибута.

Смотрите: [ksAttributeObject::ksGetAttrRow](ksattributeobject_ksgetattrrow.html), [ksAttributeObject::ksSetAttrRow](ksattributeobject_kssetattrrow.html).

4\. Добавить строку к табличному атрибуту.

Смотрите: [ksAttributeObject::ksAddAttrRow](ksattributeobject_ksaddattrrow.html).

5\. Установить/получить пользовательские параметры макроэлемента.

Смотрите: [ksDocument2D::ksSetMacroParam](ksdocument2d_kssetmacroparam.html), [ksDocument2D::ksGetMacroParam](ksdocument2d_ksgetmacroparam.html).

6\. Получить запись из базы данных.

Смотрите: [ksDataBaseObject::ksReadRecord](ksdatabaseobject_ksreadrecord.html).

7\. Изменить значение компоненты в колонке.

Смотрите: [ksSpecification::ksSpcChangeValue](ksspecification_ksspcchangevalue.html).

8\. Установить/получить пользовательские параметры компоненты (модели подсборки).

9\. Установить/получить пользовательские параметры макроэлемента 3D.

Смотрите: [ksMacro3DDefinition::SetUserParam](ksmacro3ddefinition_setuserparam.html), [ksMacro3DDefinition::GetUserParam](ksmacro3ddefinition_getuserparam.html).

10\. Для поддержки Unicode в интерфейс [ksLtVariant](ksltvariant.html) добавлено свойство [ksLtVariant::wstrVal](ksltvariant_wstrval.html). В динамический массив для строковых данных требуется добавлять однотипные типы строковых параметров. Они должны быть или все типа ltv_WStr или все типа ltv_Str. Это критично при работе с атрибутами.

При получении пользовательских параметров требуется использовать тот же тип, что и при записи параметров. При работе с базой данных при создании отношения с помощью функции [ksDataBaseObject::ksRChar](ksdatabaseobject_ksrchar.html) требуется в массив добавить ksLtVariant с типом ltv_Str. При использовании функции [ksDataBaseObject::ksRCharW](ksdatabaseobject_ksrcharw.html) требуется добавить ksLtVariant с типом ltv_WStr.

11\. Одновременное использование методов [ksUserParam::userParams](ksuserparam_userparams.html) и [ksUserParam::GetUserArray](ksuserparam_getuserarray.html) и [ksUserParam::SetUserArray](ksuserparam_setuserarray.html) не допускается.

Смотрите также: [KompasObject](kompasobject.html)

Подразделы:

[ksUserParam - свойства ](ksuserparam_props.html)

[ksUserParam - методы ](ksuserparam_methods.html)
