Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step10")> _
Public Class Step10

  ' step10 - Работа с объектами спецификации

  ' 1. Cоздадим тип атрибута болта             - TypeAttrBolt
  ' 2. Cоздать объект спецификации деталь      - CreateDet
  ' 3. Cоздать стандартный объект              - CreateStandart
  ' 4. Конвертировать спецификацию во фрагмент - DecomposeSpc
  ' 5. Просмотреть спецификацию                - ShowSpc

  Dim iKompasObject As Kompas6API5.Application ' Интерфейс KompasObject
  Dim doc As Kompas6API5.Document2D ' Интерфейс ksDocument2D
  Dim specActiv As Kompas6API5.SpcDocument ' Интерфейс ksSpcDocument
  Dim iDocument2D As Kompas6API5.Document2D ' Интерфейс ksDocument2D
  Dim spec As Kompas6API5.Specification ' Интерфейс ksSpecification

  Const SPC_NAME As Short = 5

  ' Cоздадим объект спецификации для раздела "Детали"

  Function EditSpcObjDet(geom As Integer) As Integer
    Dim spcObj As Integer
    spcObj = 0
    ' Если редактируем макро объект , то ввойдем в режим редактирования объекта
    If iDocument2D.ksEditMacroMode Then
      ' Получить указатель объекта СП по геометрии для текущего графического документа
      spcObj = spec.ksGetSpcObjForGeom("graphic.lyt", 1, 0, 1, 1)
      ' Ввойдем в режим редактирования
      If spec.ksSpcObjectEdit(spcObj) = 0 Then
        spcObj = 0
      End If
    End If

    ' Если объекта нет, создать объект спецификации в графическом документе
    Dim iPar As Kompas6API5.UserParam
    Dim iItem As Kompas6API5.LtVariant
    Dim iArr As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray ' Интерфейс ksLtVariant ' Интерфейс ksUserParam
    If spcObj Or spec.ksSpcObjectCreate("graphic.lyt", 1, 20, 0, 0, 0) Then
      ' Создать интерфейс параметров пользователя
      iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)

      ' Создать интерфейс для хранения данных некоторого типа
      iItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)

      ' Создать интерфейс параметров динамического массива
      iArr = iKompasObject.GetDynamicArray(LTVARIANT_ARR)

      ' Если какой-то из интерфейсов создать не удалось - выходим из процедуры
      If iPar Is Nothing Or iItem Is Nothing Or iArr Is Nothing Then
        EditSpcObjDet = 0
        Exit Function
      End If

      iPar.Init() ' Инициализация параметров пользователя
      iPar.SetUserArray(iArr) ' Задать массив данных
      iItem.Init() ' Инициализация интерфейса для хранения данных некоторого типа
      iItem.strVal = "Втулка" ' Тип данных строза - значение "Втулка"
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив

      ' Изменить значение компоненты - наименование
      spec.ksSpcChangeValue(5, 1, iPar, STRING_ATTR_TYPE)

      ' Подключим геометрию
      If geom Then
        spec.ksSpcIncludeReference(geom, 1)
      End If

      spcObj = spec.ksSpcObjectEnd() ' Завершить создание объекта спецификации
      ' Если объект спецификации создан дадим возможность пользователю на него посмотреть и
      ' отредактировать. Функцию нужно запускать вне Cursor и Placement
      If spcObj Then
        ' Редактирование объекта спецификации, запускает окно редактирования
        ' для объекта спецификации, расположенного в графическом документе
        spec.ksEditWindowSpcObject(spcObj)
        EditSpcObjDet = spcObj
        Exit Function
      End If
    End If
    EditSpcObjDet = 0
  End Function

  ' Отрисовать позиционную линию выноски
  ' Уже проверено, что объект спецификации есть
  ' Функцию нужно запускать вне Cursor и Placement

  Sub DrawPosLeader(ByRef spcObj As Integer)
    Dim iInfo As Kompas6API5.RequestInfo ' Интерфейс ksRequestInfo
    ' Создать интерфейс параметров запроса к системе
    iInfo = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    ' Если интерфейс создать не удалось - выходим из процедуры
    If iInfo Is Nothing Then
      Exit Sub
    End If

    iInfo.Init() ' Инициализация интерфейса параметров запроса к системе
    Dim flag As Boolean ' Повторить запрос к системе
    flag = False
    Dim posLeater As Integer ' Позиционная линия выноски
    posLeater = 0
    Dim x1, y1 As Double ' Координаты точки ввода

    Dim j1 As Short
    Do
      ' Строка или идентификатор меню состава команд
      iInfo.commandsString = "!Создать новую линию выноски !Подключить существующую "
      ' Cтрока или идентификатор приглашения
      iInfo.prompt = "Укажите позиционную линию выноски"
      ' Интерактивный ввод точки или команды
      j1 = iDocument2D.ksCursor(iInfo, x1, y1, Nothing)
      Select Case j1
        Case 1 ' Создать новую линию выноски
          posLeater = iDocument2D.ksCreateViewObject(POSLEADER_OBJ)
          flag = False
        Case 2 ' Подключить существующую
          ' Строка или идентификатор меню состава команд
          iInfo.prompt = "Укажите линию выноски"
          ' Интерактивный ввод точки или команды
          If iDocument2D.ksCursor(iInfo, x1, y1, Nothing) Then
            ' Найти ближайший к заданной точке объект вида
            ' Размер стороны окошка-ловушки с центром (x1, y1) = 100
            posLeater = iDocument2D.ksFindObj(x1, y1, 100)
            ' Узнать тип полученного графического объекта
            If posLeater = 0 Or iDocument2D.ksGetObjParam(posLeater, Nothing, 0) <> POSLEADER_OBJ Then
              iKompasObject.ksError("Ошибка! Объект не позиционная линия выноски!")
              posLeater = 0
              flag = True
            Else
              flag = False
            End If
          Else
            flag = False
          End If
        Case -1
          ' Найти ближайший к заданной точке объект вида
          ' Размер стороны окошка-ловушки с центром (x1, y1) = 100
          posLeater = iDocument2D.ksFindObj(x1, y1, 100)
          ' Узнать тип полученного графического объекта
          If posLeater = 0 Or iDocument2D.ksGetObjParam(posLeater, Nothing, 0) <> POSLEADER_OBJ Then
            iKompasObject.ksError("Ошибка! Объект не позиционная линия выноски!")
            posLeater = 0
            flag = True
          Else
            flag = False
          End If
      End Select
    Loop Until flag = False

    ' Линия выноски есть, подключим ее к объекту спецификации
    If posLeater Then
      ' Ввойдем в режим редактирования объекта спецификации и подключим линию выноски
      If spec.ksSpcObjectEdit(spcObj) Then ' Принять объект спецификации для редактирования
        ' Добавить или изменить геометрию или линии-выноски в объекте спецификации
        ' posLeater - Группа объектов или объект вида;
        ' 1 - очистить предыдущую геометрию, 0 - добавить к предыдущей
        spec.ksSpcIncludeReference(posLeater, True)
        ' Завершить редактирование объекта спецификации
        spec.ksSpcObjectEnd()
      End If
    End If
  End Sub

  ' Cоздадим тип атрибута болта

  Sub TypeAttrBolt()
    Dim iattr As Kompas6API5.AttributeObject ' Интерфейс ksAttributeObject
    ' Создать интерфейс для работы с атрибутами.
    iattr = iKompasObject.GetAttributeObject()

    Dim itype As Kompas6API5.AttributeTypeParam ' Интерфейс ksAttributeTypeParam
    ' Создать интерфейс параметров типа табличного атрибута
    itype = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_AttributeType)

    Dim icol As Kompas6API5.ColumnInfoParam ' Интерфейс ksColumnInfoParam
    ' Создать интерфейс параметров столбца табличного атрибута
    icol = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)

    ' Если какой-то из интерфейсов создать не удалось - выходим из процедуры
    Dim iArr As Kompas6API5.DynamicArray
    Dim numbType As Double ' Интерфейс ksDynamicArray
    If Not itype Is Nothing And Not icol Is Nothing And Not iattr Is Nothing Then
      itype.Init() ' Инициализация данных для создания шаблона
      icol.Init()
      itype.header = "Болт111" ' Заголовoк-комментарий типа
      itype.rowsCount = 1 ' Кол-во строк в таблице
      itype.flagVisible = True ' Видимый, невидимый   в таблице
      itype.password = "" ' Пароль, если не пустая строка  - защищает от
      ' несанкционированного изменения типа
      itype.key1 = 10 ' Рекомендуется как код разработчика
      itype.key2 = 20 ' Рекомендуется как код атрибута
      itype.key3 = 30 ' Рекомендуется как код разработчика
      itype.key4 = 0 ' Системный код атрибута

      iArr = itype.GetColumns() ' массив колонок атрибута (Массив полей записи)
      ' Если интерфейс получить не удалось - выходим из процедуры
      If Not iArr Is Nothing Then
        ' Колонка 1 "Имя элем."
        icol.header = "Имя элем." ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 1 ' Дополнительный признак, который позволит
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "Болт" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 2 "Исполнение"
        icol.header = "Исполнение" ' Заголовoк-комментарий столбца
        icol.type = UINT_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 3 ' Дополнительный признак, который позволит
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "1" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 3 "Резьба"
        icol.header = "Резьба" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "M" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 4 "Диаметр"
        icol.header = "Диаметр" ' Заголовoк-комментарий столбца
        icol.type = UINT_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 3 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "12" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 5 "разделитель"
        icol.header = "" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "x" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 6 "Шаг"
        icol.header = "Шаг" ' Заголовoк-комментарий столбца
        icol.type = FLOAT_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 3 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "1.25" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 7 "Поле допуска"
        icol.header = "Поле допуска" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 3 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "-6g" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 8 "разделитель"
        icol.header = "" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "x" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 9 "Длина"
        icol.header = "Длина" ' Заголовoк-комментарий столбца
        icol.type = UINT_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 3 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "60" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 10 "Кл. прочности"
        icol.header = "Кл. прочности" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "58" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 11 "Материал"
        icol.header = "Материал" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = ".35Х" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 12 "Покрытие"
        icol.header = "Покрытие" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = ".16" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 13 "ГОСТ"
        icol.header = "ГОСТ" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "ГОСТ" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 14 "Номер"
        icol.header = "Номер" ' Заголовoк-комментарий столбца
        icol.type = UINT_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 2 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "7808" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 15 "разделитель"
        icol.header = "" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "-" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив

        ' Колонка 16 "Год"
        icol.header = "Год" ' Заголовoк-комментарий столбца
        icol.type = STRING_ATTR_TYPE ' Тип данных в столбце - <ldefin2d.bas>
        icol.key = 0 ' Дополнительный признак, который позволит отличить две переменные с одинаковым типом
        ' отличить две переменные с одинаковым типом (очередность сортировки)
        icol.def = "70" ' Значение по умолчанию
        icol.flagEnum = False ' Флаг включающий режим, когда значение поля атрибута
        ' будет заполнятся из массива перечисленных значений 1 и 0 отключен
        iArr.ksAddArrayItem(-1, icol) ' Добавим колонку в массив
      End If

      ' Создать тип атрибута
      numbType = iattr.ksCreateAttrType(itype, iKompasObject.ksChoiceFile("*.lat", "", False))
      If numbType Then
        iKompasObject.ksMessage("номер типа атрибута = " & numbType)
      End If
      ' Удалим массив колонок
      iArr.ksDeleteArray()
    End If
  End Sub

  ' Cоздать объект спецификации деталь

  Sub CreateDet()
    Dim gr As Integer ' Указатель группы объектов
    ' Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
    gr = iDocument2D.ksNewGroup(0)
    iDocument2D.ksLineSeg(20, 30, 70, 30, 2)
    iDocument2D.ksLineSeg(70, 30, 70, 80, 2)
    iDocument2D.ksLineSeg(70, 80, 20, 80, 2)
    iDocument2D.ksLineSeg(20, 80, 20, 30, 2)
    iDocument2D.ksEndGroup() ' Завершить создание группы объектов

    ' Создать объект спецификации
    Dim spcObj As Integer
    spcObj = EditSpcObjDet(gr) ' Cоздадим объект спецификации для раздела "Детали"

    If spcObj Then ' Объект спецификации создан
      DrawPosLeader(spcObj) ' Отрисовать позиционную линию выноски
    End If
  End Sub

  ' Создать стандартный объект

  Sub CreateStandart()
    ' Dim geom As Object
    Dim spcObj As Integer
    spcObj = 0

    ' Если редактируем макро объект , то ввойдем в режим редактирования объекта
    If iDocument2D.ksEditMacroMode Then
      ' Получить указатель объекта СП по геометрии для текущего графического документа
      spcObj = spec.ksGetSpcObjForGeom("graphic.lyt", 1, 0, 1, 1)
      ' Войдем в режим редактирования
      If spec.ksSpcObjectEdit(spcObj) = 0 Then
        spcObj = 0
      End If
    End If

    ' Если объекта нет, создать объект спецификации в графическом документе
    Dim iPar As Kompas6API5.UserParam
    Dim iItem As Kompas6API5.LtVariant
    Dim iArr As Kompas6API5.DynamicArray
    Dim uBuf As Short ' Целочисленный буффер ' Интерфейс ksDynamicArray ' Интерфейс ksLtVariant ' Интерфейс ksUserParam
    If spcObj Or spec.ksSpcObjectCreate("graphic.lyt", 1, 25, 0, 313277777065.0#, 0) Then
      ' Создать интерфейс параметров пользователя
      iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)

      ' Создать интерфейс для хранения данных некоторого типа
      iItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)

      ' Создать интерфейс параметров динамического массива
      iArr = iKompasObject.GetDynamicArray(LTVARIANT_ARR)

      ' Если какой-то из интерфейсов создать не удалось - выходим из процедуры
      If iPar Is Nothing Or iItem Is Nothing Or iArr Is Nothing Then
        Exit Sub
      End If

      iPar.Init() ' Инициализация параметров пользователя
      iPar.SetUserArray(iArr) ' Задать массив данных
      iItem.Init() ' Инициализация интерфейса для хранения данных некоторого типа
      iItem.strVal = "Болт111" ' Тип данных строза - значение "Болт111"
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив
      spec.ksSpcChangeValue(5, 1, iPar, STRING_ATTR_TYPE) ' Изменить значение компоненты - наименование

      spec.ksSpcVisible(SPC_NAME, 2, 1) ' Включим исполнение

      iArr.ksClearArray() ' Очистим массив
      iItem.Init() ' Инициализация параметров пользователя
      uBuf = 2 ' Исполнение
      iItem.intVal = uBuf ' Тип данных целое - значение 2
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив
      spec.ksSpcChangeValue(SPC_NAME, 2, iPar, UINT_ATTR_TYPE) ' Изменить значение компоненты - исполнение

      ' Изменим диаметр
      iArr.ksClearArray() ' Очистим массив
      iItem.Init() ' Инициализация параметров пользователя
      iItem.doubleVal = 40 ' Диаметр резьбы
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив
      spec.ksSpcChangeValue(SPC_NAME, 4, iPar, DOUBLE_ATTR_TYPE) ' Изменить значение компоненты - диаметр

      ' Мелкий шаг
      iArr.ksClearArray() ' Очистим массив
      iItem.Init() ' Инициализация параметров пользователя
      iItem.floatVal = 1
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив

      spec.ksSpcVisible(SPC_NAME, 5, 1) ' Включить шаг и его разделитель
      spec.ksSpcVisible(SPC_NAME, 6, 1)
      spec.ksSpcChangeValue(SPC_NAME, 6, iPar, FLOAT_ATTR_TYPE) ' Изменить значение компоненты - шаг

      ' Выключить поле допуска
      spec.ksSpcVisible(SPC_NAME, 7, 0)

      ' Изменить длину
      iArr.ksClearArray() ' Очистим массив
      iItem.Init() ' Инициализация параметров пользователя
      iItem.intVal = 55 ' Длина стержня
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив
      spec.ksSpcChangeValue(SPC_NAME, 9, iPar, UINT_ATTR_TYPE) ' Изменить значение компоненты - длина стержня

      spec.ksSpcVisible(SPC_NAME, 10, 0) ' Выключить класс прочности
      spec.ksSpcVisible(SPC_NAME, 11, 0) ' Выключить материал
      spec.ksSpcVisible(SPC_NAME, 12, 0) ' Выключить покрытие

      ' Изменить ГОСТ
      iArr.ksClearArray() ' Очистим массив
      iItem.Init() ' Инициализация параметров пользователя
      iItem.floatVal = 7808 ' ГОСТ
      iArr.ksAddArrayItem(-1, iItem) ' Добавим данное в массив
      spec.ksSpcChangeValue(SPC_NAME, 14, iPar, UINT_ATTR_TYPE) 'Изменить значение компоненты - ГОСТ

      ' Подключим геометрию
      'UPGRADE_WARNING: Couldn't resolve default property of object geom. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ' If geom <> 0 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object geom. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ' spec.ksSpcIncludeReference(geom, 1)
      'End If

      spcObj = spec.ksSpcObjectEnd ' Завершить редактирование объекта спецификации
      ' Если объект спецификации создан, дадим возможность пользователю на него посмотреть и
      ' отредактировать.  Функцию нужно запускать вне Cursor и Placement
      If spcObj Or spec.ksEditWindowSpcObject(spcObj) Then
        ' Редактирование объекта спецификации, запускает окно редактирования
        ' для объекта спецификации, расположенного в графическом документе
        DrawPosLeader(spcObj)
      End If
    End If
  End Sub

  ' Конвертировать спецификацию во фрагмент

  Sub DecomposeSpc()
    Dim i As Object
    Dim pSpc As Integer ' Указатель на документ спецификации
    pSpc = specActiv.reference ' Берем текущий документ спецификацию
    If pSpc = 0 Then ' Если документа нет - выходим из процедуры
      Exit Sub
    End If

    ' Получим количество листов спецификации
    Dim pageCount As Short
    pageCount = specActiv.ksGetSpcDocumentPagesCount

    Dim ispcGabarit As Kompas6API5.RectParam ' Интерфейс ksRectParam
    ' Создать интерфейс параметров прямоугольника по диагональным точкам
    ispcGabarit = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RectParam)
    If ispcGabarit Is Nothing Then ' Если интерфейс создать не удалось - выходим из процедуры
      Exit Sub
    End If

    doc.ksGetObjGabaritRect(pSpc, ispcGabarit) ' Получим габариры одного листа спецификации

    ' Создадим фрагмент
    Dim idocPar As Kompas6API5.DocumentParam ' Интерфейс ksDocumentParam
    ' Создать интерфейс параметров документа
    idocPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_DocumentParam)
    If idocPar Is Nothing Then ' Если интерфейс создать не удалось - выходим из процедуры
      Exit Sub
    End If

    idocPar.Init() ' Инициализация интерфейса
    idocPar.regime = 0 ' Режим редактирования - видимый
    idocPar.type = lt_DocFragment ' Тип документа - фрагмент
    doc.ksCreateDocument(idocPar) ' Создадим фрагмент

    Dim group As Integer
    Dim imathBop As Kompas6API5.MathPointParam
    Dim imathTop As Kompas6API5.MathPointParam
    Dim column As Short
    Dim x As Double
    Dim row As Short
    Dim y As Double ' Интерфейс ksMathPointParam
    For i = 0 To pageCount - 1
      'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      group = doc.ksDecomposeObj(pSpc, 0, 0.4, i + 1) ' Разрушить лист спецификации во временную группу

      If group Then ' Получили временную группу i-го листа спецификации
        imathBop = ispcGabarit.GetpBot ' Получить параметры левой нижней точки прямоугольника
        imathTop = ispcGabarit.GetpTop ' Получить параметры правой верхней точки прямоугольника

        ' Расчет координат
        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Mod has a new behavior. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="9B7D5ADD-D8FE-4819-A36C-6DEDAF088CC7"'
        column = i Mod 3 ' i%3

        x = (imathTop.x - imathBop.x + 5) * column

        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        row = i \ 3

        y = (imathTop.y - imathBop.y + 5) * row

        doc.ksMoveObj(group, x, -y) ' Cдвинули группу
        doc.ksStoreTmpGroup(group) ' Поставить временную группу в вид
        doc.ksClearGroup(group, 1) ' Очистить группу объектов
        doc.ksDeleteObj(group) ' Удалить группу
      End If
    Next
    iKompasObject.ksMessage("Декомпозировано = " & pageCount & " листов СП")
  End Sub

  ' Просмотреть текущую спецификацию

  Sub ShowSpc()
    Dim i As Object
    Dim iIter As Kompas6API5.Iterator ' Интерфейс ksIterator
    iIter = iKompasObject.GetIterator() ' Получить интерфейс итератора

    Dim obj As Integer
    Dim count As Short
    Dim ispcColPar As Kompas6API5.SpcColumnParam
    Dim columnType As Integer
    Dim ispoln As Integer
    Dim blok As Integer
    Dim buf As String
    Dim colNumb As Short ' Указатель на строку, в которую требуется положить полученный текст ' Номер блока, начиная с 0 ' Номер исполнения данного типа ' Тип колонки ' Интерфейс ksSpcColumnParam ' Указатель на объект
    If Not iIter Is Nothing Then ' Интерфейс получен
      ' Создаем итератор для навигации по текущей спецификации
      ' Если функция вызывается в графическом документе, то итератор создается для объектов, образованных по описанию,
      ' определяемому именем библиотеки стилей спецификации и номером стиля.
      ' В документе-спецификации параметры nameLib и styleNumb не используются ( т.к. все объекты в ней создаются по
      ' единственному описанию, однозначно определяемому текущим стилем )
      iIter.ksCreateSpcIterator(CStr(0), 0, 0) '

      If iIter.reference Then ' Итератор создан
        obj = iIter.ksMoveIterator("F") ' Встаем на первый объект спецификации

        If specActiv.ksExistObj(obj) Then ' Проверить существование объекта

          Do
            ' Узнаем количество колонок у базового объекта спецификации
            count = spec.ksGetSpcTableColumn(CStr(0), 0, 0)
            iKompasObject.ksMessage("Кол-во колонок = " & count)

            For i = 1 To count ' Пройдем по всем колонкам
              ' Для текущего номера определим тип колонки, номер исполнения и блок
              ' Создать интерфейс параметров колонки спецификации
              ispcColPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_SpcColumnParam)

              ' По номеру колонки для данного объекта спецификации получить тип колонки,
              ' номер колонки данного типа, номер блока.
              'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If spec.ksGetSpcColumnType(obj, i, ispcColPar) Then

                ' Возьмем текст
                columnType = ispcColPar.columnType
                ispoln = ispcColPar.ispoln
                blok = ispcColPar.block
                ' Выдать текст из определенной колонки объекта спецификации
                buf = spec.ksGetSpcObjectColumnText(obj, columnType, ispoln, blok)
                ' Для данного объекта спецификации по типу колонки и номеру блока получить номер колонки
                colNumb = spec.ksGetSpcColumnNumb(obj, ispcColPar.columnType, ispcColPar.ispoln, ispcColPar.block)

                'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iKompasObject.ksMessage(" text = " & buf & ",columnType = " & columnType & ", ispoln = " & ispoln & ", block = " & blok & ", i = " & i & ", colNumb = " & colNumb)
              End If
            Next

            obj = iIter.ksMoveIterator("N") ' Встаем на следующий объект спецификации
          Loop Until obj = 0
        End If

        iIter.ksDeleteIterator() ' Удалить блок параметров навигации по модели
      End If
    End If
  End Sub

  ' Определить имя библиотеки

  Public Function GetLibraryName() As String
    GetLibraryName = "Hавигация по модели" ' Имя библиотеки
  End Function

  ' Сформировать меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1 ' Команда 1 - Создать шаблон обозначения Болт
        ExternalMenuItem = "Создать шаблон обозначения Болт"
        command_Renamed = 1
      Case 2 ' Команда 2 - Создать объект для раздела Детали
        ExternalMenuItem = "Создать объект для раздела Детали"
        command_Renamed = 2
      Case 3 ' Команда 3 - Создать объект для раздела Стандартные изделия
        ExternalMenuItem = "Создать объект для раздела Стандартные изделия"
        command_Renamed = 3
      Case 4 ' Команда 4 - Конвертировать спецификацию во фрагмент
        ExternalMenuItem = "Конвертировать спецификацию во фрагмент"
        command_Renamed = 4
      Case 5 ' Команда 5 - Просмотреть текущую спецификацию
        ExternalMenuItem = "Просмотреть текущую спецификацию"
        command_Renamed = 5
      Case Else ' Завершение формирования меню
        itemType = 3 'ENDMENU'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  ' Головная функция библиотеки - вызывается при выборе пункта меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal Kompas As Kompas6API5.Application)
    iKompasObject = Kompas ' Интерфейс приложения КОМПАС

    If iKompasObject Is Nothing Then ' Если интерфейс не задан - выходим
      Exit Sub ' и ничего не делаем
    End If

    If command_Renamed = 1 Then ' Команда 1
      TypeAttrBolt() ' Создать шаблон обозначения Болт
    End If

    If command_Renamed = 2 Or command_Renamed = 3 Then ' Команда 2 или Команда 3
      iDocument2D = iKompasObject.ActiveDocument2D ' Возьмем интерфейс текущего 2D документа

      If iDocument2D Is Nothing Then ' Если документа нет или текущий не 2D документ
        Exit Sub ' Выйдем из процедуры ничего не делая
      End If

      spec = iDocument2D.GetSpecification ' Возьмем интерфейс спецификации

      If spec Is Nothing Then ' Если интерфейс получить не удалось
        Exit Sub ' Выйдем из процедуры ничего не делая
      End If

      Select Case command_Renamed
        Case 2
          CreateDet() ' Создать объект для раздела Детали
        Case 3
          CreateStandart() ' Создать объект для раздела Стандартные изделия
      End Select
    End If


    If command_Renamed = 4 Or command_Renamed = 5 Then ' Команда 4 или Команда 5

      doc = iKompasObject.Document2D ' Создадим интерфейс 2D документа

      specActiv = iKompasObject.SpcActiveDocument ' Возьмем интерфейс текущего документа спецификации
      If doc Is Nothing Or specActiv Is Nothing Then ' Если документа нет или текущий не документ спецификации
        Exit Sub ' Выйдем из процедуры ничего не делая
      End If

      spec = specActiv.GetSpecification ' Возьмем интерфейс спецификации

      If spec Is Nothing Then ' Если интерфейс получить не удалось
        Exit Sub ' Выйдем из процедуры ничего не делая
      End If

      Select Case command_Renamed
        Case 4
          DecomposeSpc() ' Конвертировать спецификацию во фрагмент
        Case 5
          ShowSpc() ' Просмотреть текущую спецификацию
      End Select
    End If

    iKompasObject.ksMessageBoxResult() ' Результат выполнения команды

  End Sub

  <ComRegisterFunctionAttribute()> _
  Friend Shared Sub RegisterKompasLib(ByVal typeToRegister As Type)
    Try
      Dim regKey As RegistryKey
      regKey = Registry.LocalMachine
      Dim keyName As String
      keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
      regKey = regKey.OpenSubKey(keyName, True)
      regKey.CreateSubKey("Kompas_Library")
      regKey = regKey.OpenSubKey("InprocServer32", True)
      regKey.SetValue(Nothing, System.Environment.GetFolderPath(Environment.SpecialFolder.System) + "\mscoree.dll")
      regKey.Close()

    Catch e As Exception
      MsgBox(e.Message, MsgBoxStyle.OkOnly)
    End Try

  End Sub

  <ComUnregisterFunctionAttribute()> _
  Friend Shared Sub UnregisterKompasLib(ByVal typeToRegister As Type)
    Dim regKey As RegistryKey
    regKey = Registry.LocalMachine
    Dim keyName As String
    keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
    regKey = regKey.OpenSubKey(keyName, True)
    regKey.DeleteSubKey("Kompas_Library")
    regKey.Close()
  End Sub
End Class