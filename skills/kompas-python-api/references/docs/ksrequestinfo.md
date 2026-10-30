# Запрос к системе (Интерфейс ksRequestInfo)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) |  Scroll [ [ [ ](ksrequestinfo_props.html "К следующему разделу")](cc1711812.html "На уровень выше")](kslayerparam_init.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров запроса к системе.

Аналог данных параметров при использовании API экспортных функций - [RequestInfo](structrequestinfo.html).

Примечания:

1\. Данный интерфейс позволяет установить параметры процесcов:

[ksDocument2D::ksCursor](ksdocument2d_kscursor.html);

[ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html);

[ksDocument2D::ksCommandWindow](ksdocument2d_kscommandwindow.html).

2\. Методами данного интерфейса можно получить/изменить:

•строку или идентификатор строки приглашения,

•строку или идентификатор строки заголовка окна,

•строку меню или идентификатор меню состава команд,

•строку с именем стандартного курсора или идентификатор курсора,

•признак динамического запроса,

•идентификатор приложения (dll), в котором размещены ресурсы процесса,

•функцию обратной связи процесса.

3\. Указатель на интерфейс можно получить при помощи метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html).

4\. В случае динамического запроса функция обратной связи вызывается по перемещению курсора. В случае статического запроса функция обратной связи вызывается по щелчку мыши.

Смотрите также:[ KompasObject](kompasobject.html)

Подразделы:

[RequestInfo - свойства ](ksrequestinfo_props.html)

[RequestInfo - методы ](ksrequestinfo_methods.html)
