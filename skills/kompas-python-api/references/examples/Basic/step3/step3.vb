Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step3")> _
Public Class Step3
  ' step3 - Объекты

  ' 1.  Создать документ - WorkDocument
  ' 2.  Виды             - DrawView
  ' 3.  Слои             - DrawLayer
  ' 4.  Группы           - DrawGroup
  ' 5.  Именная группа   - WorkNameGroup
  ' 6.  Отрезки          - DrawLineSeg
  ' 7.  Дуги             - DrawArc
  ' 8.  Линии            - DrawLine
  ' 9.  Окружности       - DrawCircle
  ' 10. Точки            - DrawPoint
  ' 11. Bezier-сплайны   - DrawBezier
  ' 12. Штриховка        - DrawHatch
  ' 13. Текст            - DrawText

  Public Kompas As Kompas6API5.Application ' Интерфейс KompasObject

  ' Работа с документом

  Sub WorkDocument(ByRef doc As Kompas6API5.Document2D)

    Dim docPar As Kompas6API5.DocumentParam ' Интерфейс ksDocumentParam
    ' Структура параметров документа
    docPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_DocumentParam)

    Dim sheet As Kompas6API5.SheetPar
    Dim standart As Kompas6API5.StandartSheet
    Dim view As Kompas6API5.ViewParam
    Dim number As Integer ' Интерфейс ksViewParam ' Интерфейс ksStandartSheet ' Интерфейс ksSheetPar
    If Not docPar Is Nothing Then ' Интерфейс создан

      docPar.Init() ' Инициализация
      docPar.fileName = "c:\2.cdw" ' Имя  файла документа
      docPar.comment = "create document" ' Комментарий к документу
      docPar.author = "user" ' Автор документа
      docPar.regime = 0 ' Режим ( 0 - видимый, 1 - слепой )
      docPar.type = 1 ' Тип документа ( 0 - нестандартный, 1 - стандартный чертеж )

      sheet = docPar.GetLayoutParam ' Интерфейс параметров оформления

      If Not sheet Is Nothing Then ' Интерфейс создан

        sheet.shtType = 1 ' Тип штампа из указанной библиотеки для спецификации ( номер стиля из указанной библиотеки )
        sheet.layoutName = "" ' Имя библиотеки оформления,

        standart = sheet.GetSheetParam() ' Интерфейс параметров стандартного листа

        If Not standart Is Nothing Then ' Интерфейс создан

          standart.format = 3 ' Формат листа 0( А0 ) ... 4( А4 )
          standart.multiply = 1 ' Кратность формата
          standart.direct = 0 ' Расположение штампа ( 0 - вдоль короткой стороны, 1 - вдоль длинной )

          ' Создаем документ: лист, формат А3, горизонтально расположенный и с системным штампом 1
          If doc.ksCreateDocument(docPar) Then

            ' Структура параметров вида
            view = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewParam)

            If Not view Is Nothing Then ' Интерфейс создан

              view.x = 10 ' Точка привязки вида
              view.y = 20
              view.angle = 45 ' Угол поворота вида
              view.scale_ = 0.5 ' Масштаб вида
              view.color = RGB(10, 20, 10) ' Цвет вида в активном состоянии
              view.state = stACTIVE ' Состояние вида
              view.name = "user view" ' Имя вида

              number = 2

              ' У документа создадим вид с номером 2, масштабом 0.5, под углом 45 гр
              doc.ksCreateSheetView(view, number)

              doc.ksLayer(5) ' Создадим слой с номером 5

              doc.ksLineSeg(20, 10, 40, 10, 1) ' Отрисовка отрезков
              doc.ksLineSeg(40, 10, 40, 30, 1)
              doc.ksLineSeg(40, 30, 20, 30, 1)
              doc.ksLineSeg(20, 30, 20, 10, 1)

              Kompas.ksMessage("нарисовали")

              ' Получить параметры документа
              doc.ksGetObjParam(doc.reference, docPar, ALLPARAM)

              Kompas.ksMessage("type = " & docPar.type & " f = " & standart.format & " m = " & standart.multiply & " d = " & standart.direct)

              Kompas.ksMessage("Имя файла : " & docPar.fileName)
              Kompas.ksMessage("Комментарий : " & docPar.comment)
              Kompas.ksMessage("Автор : " & docPar.author)

              doc.ksSaveDocument("") ' Сохраним документ
              doc.ksCloseDocument() ' Закрыть документ
            End If
          End If
        End If
      End If
    End If

  End Sub

  ' Создать вид

  Sub DrawView(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.ViewParam ' Интерфейс ksViewParam
    ' Структура параметров вида
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewParam)

    Dim number As Integer
    Dim v As Integer
    Dim gr As Integer
    Dim p As Integer
    Dim var As Kompas6API5.LtVariant ' Интерфейс ksLtVariant
    If Not par Is Nothing Then ' Интерфейс создан

      number = 5 ' Номер вида

      par.Init() ' Инициализация
      par.x = 10 ' Точка привязки вида
      par.y = 20
      par.scale_ = 0.5 ' Масштаб вида
      par.angle = 45 ' Угол поворота вида
      par.color = RGB(10, 20, 10) ' Цвет вида в активном состоянии
      par.state = stACTIVE ' Состояние вида
      par.name = "user view" ' Имя вида

      v = doc.ksCreateSheetView(par, number) ' Создадим вид с номером 5, масштабом 0.5, под углом 45 гр.
      number = doc.ksGetViewNumber(v) ' Номер созданного вида
      Kompas.ksMessage("создали вид: ref = " & v & " number = " & number)

      ' Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
      gr = doc.ksNewGroup(0)
      doc.ksLineSeg(20, 10, 20, 30, 1)
      doc.ksLineSeg(20, 30, 40, 30, 1)
      doc.ksLineSeg(40, 30, 40, 10, 1)
      doc.ksLineSeg(40, 10, 20, 10, 1)
      doc.ksEndGroup() ' Завершить создание группы объектов

      doc.ksAddObjGroup(gr, v) ' Добавим вид в группу
      Kompas.ksMessage("добавили вид в группу")
      '    Kompas.ksMessageBoxResult

      p = doc.ksLineSeg(10, 10, 30, 30, 0) ' Нарисуем отрезок
      doc.ksAddObjGroup(gr, p) ' И добавим его в группу

      Kompas.ksMessage("добавили эл в группу")
      '    Kompas.ksMessageBoxResult

      doc.ksRotateObj(gr, 0, 0, -45) ' Повернуть группу на -45 градусов вокруг точки ( 0, 0 )

      par.Init() ' Инициализация
      doc.ksGetObjParam(v, par, ALLPARAM) ' Получить параметры видa

      Kompas.ksMessage("x =" & par.x & " y = " & par.y & " angl = " & par.angle & " name = " & par.name & " st = " & par.state)

      doc.ksOpenView(0) ' Сделать текущим системный вид ( номер 0 )

      ' состояние  вида  : только чтение
      ' Интерфейс для хранения данных некоторого типа
      var = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)

      If Not var Is Nothing Then ' Интерфейс создан

        var.Init() ' Инициализация
        var.intVal = stREADONLY ' Изменить состояние вида ( только чтение )
        doc.ksSetObjParam(v, var, VIEW_LAYER_STATE)
        'UPGRADE_NOTE: Object var may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        var = Nothing
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Создать слой

  Sub DrawLayer(ByRef doc As Kompas6API5.Document2D)
    Dim n As Integer ' Запрос номера создаваемого слоя
    If Kompas.ksReadInt("Введите номер слоя", 1, 0, 255, n) = 0 Then
      Exit Sub
    End If

    ' Переопределение текущего слоя, если слоя с заданным номером
    ' нет, такой слой создается. Слой становится текущим
    Dim lay As Integer
    lay = doc.ksLayer(n) ' Создаем слой, слой становится текущим

    doc.ksMtr(20, 15, 0, 1, 1) ' Матрица преобразования координат ( 20 по оси OX, 15 по оси OY )
    doc.ksLineSeg(-10, 0, 10, 0, 1)
    doc.ksLineSeg(10, 0, 10, 20, 1)
    doc.ksLineSeg(10, 20, -10, 20, 1)
    doc.ksLineSeg(-10, 20, -10, 0, 1)
    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    doc.ksLightObj(lay, 1) ' Подсветить слой

    ' Получить номер слоя по указателю и указатель по номеру
    Dim n1 As Short
    n1 = doc.ksGetLayerNumber(lay)
    Dim l As Integer
    l = doc.ksGetLayerReference(n1)

    Kompas.ksMessage("n = " & n & " n1 = " & n1 & " layer = " & lay & " l = " & l)

    doc.ksLightObj(lay, 0) ' Снять выделение слоя

    ' Установить параметры слоя и считать их обратно
    Dim par As Kompas6API5.LayerParam ' Интерфейс ksLayerParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LayerParam) ' Интерфейс параметров слоя

    Dim par1 As Kompas6API5.LayerParam ' Интерфейс ksLayerParam
    par1 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LayerParam) ' Интерфейс параметров слоя

    Dim var As Kompas6API5.LtVariant ' Интерфейс ksLtVariant
    If Not par Is Nothing And Not par1 Is Nothing Then ' Интерфейсы созданы
      par.Init() ' Инициализация
      par1.Init() ' Инициализация

      par.color = RGB(0, 255, 0) ' Цвет слоя в активном состоянии
      par.state = stACTIVE ' Состояние слоя
      par.name = "зеленый" ' Имя слоя

      ' Установить параметры слоя
      If Not doc.ksSetObjParam(l, par, ALLPARAM) Then
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      Else
        doc.ksGetObjParam(l, par1, ALLPARAM) ' Считать параметры слоя
        Kompas.ksMessage("col = " & par.color & " col1 = " & par1.color & " name = " & par.name & " name1 = " & par1.name)
      End If

      doc.ksLayer(0) ' Слой номер 0 становится текущим

      ' Изменить состояние слоя ( активизировать слой )
      ' Интерфейс для хранения данных некоторого типа
      var = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)

      If Not var Is Nothing Then ' Интерфейс создан

        var.Init() ' Инициализация
        var.intVal = stACTIVE ' Изменить состояние слоя ( активизировать слой )
        doc.ksSetObjParam(l, var, VIEW_LAYER_STATE)

        'UPGRADE_NOTE: Object var may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        var = Nothing
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object par1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par1 = Nothing
    End If
  End Sub

  ' Работа с группой

  Sub DrawGroup(ByRef doc As Kompas6API5.Document2D)

    Dim p1 As Integer
    p1 = doc.ksLineSeg(10, 10, 20, 10, 0) ' Первый отрезок
    Dim p2 As Integer
    p2 = doc.ksLineSeg(10, 10, 10, 20, 0) ' Второй отрезок

    Dim gr1 As Integer
    gr1 = doc.ksNewGroup(0) ' Создать модельную группу   1
    doc.ksEndGroup()

    Dim gr2 As Integer
    gr2 = doc.ksNewGroup(0) ' Создать модельную группу   2
    doc.ksEndGroup()

    doc.ksAddObjGroup(gr1, p1) ' Добавим первый отрезок в первую группу
    doc.ksAddObjGroup(gr1, p2) ' Добавим второй отрезок в первую группу

    doc.ksAddObjGroup(gr2, p1) ' Добавим первый отрезок во вторую группу
    doc.ksAddObjGroup(gr2, p2) ' Добавим второй отрезок во вторую группу

    Kompas.ksMessage("создали группы")

    doc.ksMoveObj(gr1, 10, 0) ' Сдвинули первую группу на 10 ММ
    Kompas.ksMessage("сдвинули группу на 10 ММ")

    doc.ksRotateObj(gr2, 20, 10, 45) ' Повернули вторую группу на 45 гр
    Kompas.ksMessage("повернули группу на 45 гр")

    doc.ksRotateObj(gr2, 20, 10, -45) ' Повернули вторую группу на -45 гр
    Kompas.ksMessage("повернули группу на -45 гр")

    doc.ksMoveObj(gr1, -10, 0) ' Сдвинули первую группу на -10 ММ
    Kompas.ksMessage("сдвинули группу на -10 ММ")

    doc.ksClearGroup(gr2, False) ' Очистили группу 2 ( объекты исключаются из группы )
    doc.ksDeleteObj(gr2) ' Удалим  группу 2

    Kompas.ksMessage("подсветили gr1")
    doc.ksLightObj(gr1, 1) ' Подсветили первую группу

    Kompas.ksMessage("выключили gr1")
    doc.ksLightObj(gr1, 0) ' Выключили подсветку первой группы

    Kompas.ksMessage("подсветили p1")
    doc.ksLightObj(p1, 1) ' Подсветили первый объект
    Kompas.ksMessage("выключили p1")
    doc.ksLightObj(p1, 0) ' Выключили подсветку первого объекта

    doc.ksDeleteObj(gr1) ' Удалим группу 1( объекты удалятся тоже )
    Kompas.ksMessageBoxResult() ' Результат выполнения
  End Sub

  '  Работа с именнованной группой

  Sub WorkNameGroup(ByRef doc As Kompas6API5.Document2D)
    Dim gr As Integer
    Dim p As Integer

    ' Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
    gr = doc.ksNewGroup(0)
    p = doc.ksLineSeg(20, 20, 40, 20, 1)
    doc.ksLineSeg(40, 20, 40, 40, 1)
    doc.ksLineSeg(40, 40, 20, 40, 1)
    doc.ksLineSeg(20, 40, 20, 20, 1)
    doc.ksEndGroup() ' Завершить создание группы объектов

    ' Сохранить группу объектов в модели с указанным именем
    ' Группа автоматически сохраняется в чертеже при его записи
    ' В противном случае группа действительна только в текущем сеансе работы
    ' Если указатель группы равен нулю, то сохраняется группа селектирования
    ' КОМПАС-ГРАФИК (выделенные объекты чертежа).
    If doc.ksSaveGroup(gr, "group1") = 0 Then
      Exit Sub ' Если сохранить не удалось - выход из процедуры
    End If

    Dim gr1 As Integer
    gr1 = doc.ksGetGroup("group1") ' Получить указатель на именованную группу

    If gr1 = 0 Then ' Если группы нет - выход из процедуры
      Exit Sub
    End If

    Dim c As Integer
    c = doc.ksCircle(30, 30, 10, 1) ' Создание окружности
    doc.ksAddObjGroup(gr1, c) ' Добавить новый объект в группу

    doc.ksLightObj(gr1, 1) ' Подсветить группу
    Kompas.ksMessage("добавили объект в именную группу")
    doc.ksLightObj(gr1, 0) ' Снять подсветку с группы

    doc.ksExcludeObjGroup(gr1, p) ' Исключить объект из группы

    doc.ksLightObj(gr1, 1) ' Подсветить группу
    Kompas.ksMessage("исключили объект из именной группы")
    doc.ksLightObj(gr1, 0) ' Снять подсветку с группы
  End Sub

  ' Создать отрезок

  Sub DrawLineSeg(ByRef doc As Kompas6API5.Document2D)
    ' Построить отрезок
    ' Матрица преобразования координат ( 30 по оси OX, 25 по оси OY, поворот на 45 градусов )
    doc.ksMtr(30, 20, 45, 1, 1)
    Dim p As Integer ' Указатель на отрезок
    p = doc.ksLineSeg(30, 20, 60, 20, 1) ' Создание отрезка

    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    ' Взять параметры отрезка
    Dim par As Kompas6API5.LineSegParam ' Интерфейс ksLineSegParam
    ' Структура параметров отрезка
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LineSegParam)

    Dim t As Short
    If Not par Is Nothing Then ' Интерфейс создан
      t = doc.ksGetObjParam(p, par, ALLPARAM) ' Получить параметры отрезка

      Kompas.ksMessage("t = " & t & " x1 = " & par.x1 & " y1 = " & par.y1 & " x2 = " & par.x2 & " y2 = " & par.y2 & " tl = " & par.style)

      ' Задать параметры отрезка
      par.x1 = 0 ' Координаты начальной точки
      par.y1 = 0
      par.x2 = 30 ' Координаты конечной точки
      par.y2 = 60
      par.style = 2 ' Стиль линии

      ' Заменить параметры отрезка
      If doc.ksSetObjParam(p, par, ALLPARAM) Then
        Kompas.ksMessage("Изменили объект")
      Else
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Создать дугу

  Sub DrawArc(ByRef doc As Kompas6API5.Document2D)
    ' Построить дугу
    doc.ksMtr(10, 10, 0, 1, 1) ' Матрица преобразования координат ( 10 по оси OX, 10 по оси OY )
    Dim p As Integer
    p = doc.ksArcByAngle(30, 20, 20, 45, 135, 1, 1) ' Создать дугу по углам
    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    ' взять параметры дуги  по углам
    Dim par As Kompas6API5.ArcByAngleParam ' Интерфейс ksArcByAngleParam
    ' Структура параметров дуги окружности по центру, радиусу и углам
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ArcByAngleParam)

    Dim par1 As Kompas6API5.ArcByPointParam ' Интерфейс ksArcByPointParam
    ' Структура параметров дуги по точкам
    par1 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ArcByPointParam)

    Dim t As Short
    If Not par Is Nothing And Not par1 Is Nothing Then ' Интерфейсы созданы
      t = doc.ksGetObjParam(p, par, ALLPARAM) ' Получить параметры дуги

      Kompas.ksMessage("t = " & t & " xc = " & par.xc & " yc = " & par.yc & " rad = " & par.rad & " a1 = " & par.ang1 & " a2 = " & par.ang2 & " napr = " & par.dir & " tl = " & par.style)

      ' Задать параметры дуги по точкам
      par1.xc = 40 ' Координаты центра дуги
      par1.yc = 30
      par1.rad = 10 ' Радиус
      par1.dir = 1 ' Направление построения дуги
      par1.style = 2 ' Cтиль линии
      par1.x1 = 50 ' Начальная точка дуги
      par1.y1 = 30
      par1.x2 = 40 ' Конечная точка дуги
      par1.y2 = 20

      If doc.ksSetObjParam(p, par1, 1) Then ' Заменить параметры дуги
        Kompas.ksMessage("Изменили объект")
      Else
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object par1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par1 = Nothing
    End If
  End Sub

  ' Создать вспомогательную линию

  Sub DrawLine(ByRef doc As Kompas6API5.Document2D)
    doc.ksMtr(0, 0, 45, 1, 1) ' Матрица преобразования координат ( поворот на 45 градусов )
    Dim p As Integer
    p = doc.ksLine(30, 20, 0) ' Создать вспомогательную линию
    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    ' Взять параметры вспомогательной линии
    Dim par As Kompas6API5.LineParam ' Интерфейс ksLineParam
    ' Структура параметров вспомогательной прямой
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LineParam)

    Dim t As Short
    If Not par Is Nothing Then ' Интерфейс создан
      par.Init() ' Инициализация

      t = doc.ksGetObjParam(p, par, ALLPARAM) ' Взять параметры вспомогательной линии
      Kompas.ksMessage("t = " & t & " x = " & par.x & " y = " & par.y & " alf = " & par.angle)

      ' Задать параметры вспомогательной линии
      par.x = 0 ' Координаты точки
      par.y = 0
      par.angle = 90 ' Угол наклона прямой

      If doc.ksSetObjParam(p, par, ALLPARAM) Then ' Заменить параметры вспомогательной линии
        Kompas.ksMessage("Изменили объект")
      Else
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Создать окружность

  Sub DrawCircle(ByRef doc As Kompas6API5.Document2D)
    doc.ksMtr(0, 0, 0, 2, 2) ' Матрица преобразования координат ( маштаб 2:1 )
    Dim p As Integer
    p = doc.ksCircle(30, 20, 10, 1) ' Создать окружность
    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    ' Взять параметры окружности
    Dim par As Kompas6API5.CircleParam ' Интерфейс ksCircleParam
    ' Структура параметров окружности
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_CircleParam)

    Dim t As Short
    If Not par Is Nothing Then ' Интерфейс создан
      t = doc.ksGetObjParam(p, par, ALLPARAM) ' Взять параметры окружности
      Kompas.ksMessage("t = " & t & " xc = " & par.xc & " yc = " & par.yc & " rad = " & par.rad & " tl = " & par.style)

      ' Задать параметры окружности
      par.xc = 0 ' Координаты центра окружности
      par.yc = 0
      par.rad = 20 ' Радиус окружности
      par.style = 2 ' Cтиль линии

      If doc.ksSetObjParam(p, par, ALLPARAM) Then ' Заменить параметры окружности
        Kompas.ksMessage("Изменили объект")
      Else
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Cоздать точку

  Sub DrawPoint(ByRef doc As Kompas6API5.Document2D)
    ' Cтиль отрисовки точки
    ' 0-точка, 1-крестик, 2-х-точка, 3-квадрат, 4-треугольник, 5-окружность, 6-звезда,
    ' 7-перечеркнутый квадрат

    doc.ksMtr(10, 10, 0, 1, 1) ' Матрица преобразования координат ( 10 по оси OX, 10 по оси OY )
    Dim p As Integer
    p = doc.ksPoint(30, 40, 0) ' Создать точку

    doc.ksPoint(40, 40, 1)
    doc.ksPoint(50, 40, 2)
    doc.ksPoint(60, 40, 3)
    doc.ksPoint(70, 40, 4)
    doc.ksPoint(80, 40, 5)
    doc.ksPoint(90, 40, 6)
    doc.ksPoint(100, 40, 7)
    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    ' Взять параметры точки
    Dim par As Kompas6API5.PointParam ' Интерфейс ksPointParam
    ' Структура параметров точки
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PointParam)

    Dim t As Short
    If Not par Is Nothing Then ' Интерфейс создан
      t = doc.ksGetObjParam(p, par, ALLPARAM) ' Взять параметры точки
      Kompas.ksMessage("t = " & t & " x = " & par.x & " y = " & par.y & " style = " & par.style)

      ' Задать параметры окружности
      par.x = 20 ' Координаты точки
      par.y = 30
      par.style = 7 ' Cтиль отрисовки точки

      If doc.ksSetObjParam(p, par, ALLPARAM) Then ' Заменить параметры точки
        Kompas.ksMessage("Изменили объект")
      Else
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Создать Bezier сплайн

  Sub DrawBezier(ByRef doc As Kompas6API5.Document2D)
    ' 1. Признак замкнутости кривой ( 0 - не замкнута, 1 - замкнута )
    ' 2. Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая,
    '    5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками,
    '    8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
    '    11 - тонкая, включаемая в штриховку )
    doc.ksBezier(0, 1) ' Создать Bezier сплайн
    doc.ksPoint(0, 0, 0) ' Точки входящие в кривую Безье
    doc.ksPoint(20, 20, 0)
    doc.ksPoint(50, 10, 0)
    doc.ksPoint(70, 20, 0)
    doc.ksPoint(100, 0, 0)
    Dim p As Integer
    p = doc.ksEndObj ' Функция EndObj возвращает указатель на созданный объект кривой Безье

    ' взять параметры Bezier сплайна
    Dim pPar As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    ' Структура параметров математической точки
    pPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

    Dim par As Kompas6API5.BezierParam ' Интерфейс ksBezierParam
    ' Структура параметров кривой Безье
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_BezierParam)

    Dim arr As Kompas6API5.DynamicArray
    Dim t As Short
    Dim count As Short
    Dim i As Short ' Цикл по точкам кривой Безье ' Интерфейс ksDynamicArray
    If Not pPar Is Nothing And Not par Is Nothing Then ' Интерфейсы созданы
      par.Init() ' Инициализация

      arr = par.GetMathPointArr ' Получить массив математических точек сплайна.

      If Not arr Is Nothing Then ' Интерфейс создан
        t = doc.ksGetObjParam(p, par, ALLPARAM) ' Взять параметры Bezier сплайна

        count = arr.ksGetArrayCount ' Количество элементов в массиве
        Kompas.ksMessage("t = " & t & " count = " & count & " close = " & par.closed & " tl = " & par.style)

        ' Взять точки кривой Безье
        For i = 0 To count - 1
          arr.ksGetArrayItem(i, pPar) ' Получить значение элемента массива
          Kompas.ksMessage("x[" & i & "] = " & pPar.x & " y[" & i & "] = " & pPar.y)
        Next

        ' Задать параметры кривой Безье
        arr.ksClearArray() ' Очистим массив для заполнения его новыми точками

        ' Подставим свои значения в массив точек
        pPar.x = 0 ' Координаты точки
        pPar.y = 0
        arr.ksAddArrayItem(-1, pPar) ' Добавим точку в массив, элемент добавляется в конец массива
        pPar.x = 20 ' Координаты точки
        pPar.y = 20
        arr.ksAddArrayItem(-1, pPar) ' Добавим точку в массив, элемент добавляется в конец массива
        pPar.x = 50 ' Координаты точки
        pPar.y = 10
        arr.ksAddArrayItem(-1, pPar) ' Добавим точку в массив, элемент добавляется в конец массива
        pPar.x = 70 ' Координаты точки
        pPar.y = 20
        arr.ksAddArrayItem(-1, pPar) ' Добавим точку в массив, элемент добавляется в конец массива
        pPar.x = 100 ' Координаты точки
        pPar.y = 0
        arr.ksAddArrayItem(-1, pPar) ' Добавим точку в массив, элемент добавляется в конец массива
        pPar.x = 50 ' Координаты точки
        pPar.y = -50
        arr.ksAddArrayItem(-1, pPar) ' Добавим точку в массив, элемент добавляется в конец массива

        par.style = 2 ' Cтиль линии
        par.closed = 1 ' Признак замкнутости кривой ( 0 - не замкнута, 1 - замкнута )

        If doc.ksSetObjParam(p, par, ALLPARAM) Then ' Заменить параметры Bezier сплайна
          Kompas.ksMessage("Изменили объект")
        Else
          Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
        End If

        arr.ksDeleteArray() ' Удалить массив точек кривой Безье
        'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr = Nothing
      End If

      'UPGRADE_NOTE: Object pPar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      pPar = Nothing
      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Создать штриховку

  Sub DrawHatch(ByRef doc As Kompas6API5.Document2D)
    ' Создать заштрихованный квадрат
    doc.ksMtr(30, 20, 0, 0.5, 0.5) ' Матрица преобразования координат ( 30 по оси OX, 20 по оси OY, маштаб 1:2 )
    doc.ksLineSeg(20, 30, 70, 30, 2) ' Стороны квадрата
    doc.ksLineSeg(70, 30, 70, 80, 2)
    doc.ksLineSeg(70, 80, 20, 80, 2)
    doc.ksLineSeg(20, 80, 20, 30, 2)

    ' Параметры метода ksHatch
    ' 1. Стиль штриховки ( 0 - металл, 1 - неметалл, 2 - дерево, 3 - камень естественный,
    '     4 - керамика, 5 - бетон, 6 - стекло, 7 - жидкость, 8 - естественный грунт,
    '     9 - насыпной грунт, 10 - камень искусственный, 11 - железобетон,
    '     12 - напряженный железобетон, 13 - дерево в продольном сечении, 14 - песок )
    ' 2. Угол штриховки
    ' 3. Шаг штриховки
    ' 4. Ширина полосы штриховки ( 0 - штриховать всю область )
    ' 5, 6. Базовая точка
    Dim p As Integer
    If doc.ksHatch(0, 45, 2, 0, 0, 0) Then ' Штриховка квадрата
      doc.ksLineSeg(20, 30, 70, 30, 2) ' Геометрические примитивы определяют границы штриховки
      doc.ksLineSeg(70, 30, 70, 80, 2)
      doc.ksLineSeg(70, 80, 20, 80, 2)
      doc.ksLineSeg(20, 80, 20, 30, 2)
      p = doc.ksEndObj ' Функция EndObj возвращает указатель на объект Штриховка
    Else
      Kompas.ksMessageBoxResult() ' Выдать ошибку
    End If

    doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

    ' взять параметры штриховки
    Dim par As Kompas6API5.HatchParam ' Интерфейс ksHatchParam
    ' Структура параметров штриховки
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_HatchParam)

    Dim t As Short
    If Not par Is Nothing Then ' Интерфейс создан
      par.Init() ' Инициализация

      t = doc.ksGetObjParam(p, par, ALLPARAM) ' Взять параметры штриховки
      Kompas.ksMessage("t = " & t & " tip = " & par.style & " angl = " & par.ang & " shag = " & par.step & " width = " & par.width & " x0 = " & par.x & " y0 = " & par.y)

      doc.ksMtr(0, 0, 0, 2, 2) ' Матрица преобразования координат ( маштаб 2:1 )
      ' Задать параметры штриховки
      par.x = 0.8
      ' Заменить параметры штриховки
      If doc.ksSetObjParam(p, par, ALLPARAM) Then
        Kompas.ksMessage("Изменили объект")
      Else
        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
      End If
      doc.ksDeleteMtr() ' Отключение матрицы преобразования координат

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Вывод параметров текста

  Sub PrintPar1(ByRef par2 As Kompas6API5.TextLineParam, ByRef par3 As Kompas6API5.TextItemParam, ByRef arr2 As Kompas6API5.DynamicArray)
    Dim font As Kompas6API5.TextItemFont ' Интерфейс ksTextItemFont

    Kompas.ksMessage("style = " & par2.style) ' Стиль

    Dim count As Short
    count = arr2.ksGetArrayCount ' Количество элементов массива
    Dim j As Short

    For j = 0 To count - 1 ' Цикл по коипонентам строки
      arr2.ksGetArrayItem(j, par3) ' Взять параметры компоненты строки

      font = par3.GetItemFont ' Параметры Шрифта компоненты строки текста.
      If Not font Is Nothing Then ' Параметры Шрифта получены
        Kompas.ksMessage("j = " & j & " h = " & font.height & " s = " & par3.s & " fontName = " & font.fontName)
        'UPGRADE_NOTE: Object font may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        font = Nothing
      End If
    Next
    Kompas.ksMessageBoxResult() ' Результат выполнения
  End Sub

  ' Текст

  Sub DrawText(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.ParagraphParam ' Интерфейс ksParagraphParam
    ' Структура параметров параграфа
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ParagraphParam)

    Dim par1 As Kompas6API5.TextParam ' Интерфейс ksTextParam
    par1 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextParam) ' Параметры текста

    Dim par2 As Kompas6API5.TextLineParam ' Интерфейс ksTextLineParam
    par2 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam) ' Параметры строки текста

    Dim par3 As Kompas6API5.TextItemParam ' Интерфейс ksTextItemParam
    par3 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam) ' Параметры компоненты строки текста.

    Dim itemParam As Kompas6API5.TextItemParam ' Интерфейс ksTextItemParam
    itemParam = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam) ' Параметры компоненты строки текста.

    Dim p As Integer
    Dim itemFont As Kompas6API5.TextItemFont
    Dim arr1 As Kompas6API5.DynamicArray
    Dim arr2 As Kompas6API5.DynamicArray
    Dim font As Kompas6API5.TextItemFont ' Интерфейс ksTextItemFont ' Интерфейс ksDynamicArray
    If Not par Is Nothing And Not par1 Is Nothing And Not par2 Is Nothing And Not par3 Is Nothing And Not itemParam Is Nothing Then ' Интерфейсы созданы
      par1.Init() ' Инициализация
      par2.Init() ' Инициализация
      par3.Init() ' Инициализация
      par.Init() ' Инициализация
      itemParam.Init() ' Инициализация

      par.x = 30 ' Координаты точки привязки текста
      par.y = 30
      par.height = 25 ' Высота блока форматирования
      par.width = 20 ' Ширина блока форматирования

      itemFont = itemParam.GetItemFont ' Параметры Шрифта компоненты строки текста.

      If Not itemFont Is Nothing Then ' Интерфейс получен
        itemFont.Init() ' Инициализация

        doc.ksParagraph(par) ' Параграфом называется автоматически форматируемый блок текста

        ' Пример задания дроби
        itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
        itemParam.s = "111" ' Текст компоненты
        doc.ksTextLine(itemParam) ' Задание подстроки параграфа текста

        itemFont.Init() ' Инициализация
        itemFont.SetBitVectorValue(NUMERATOR, True) ' Числитель, наклон, высота дроби
        itemFont.SetBitVectorValue(ITALIC_ON, True) ' в 1.5 раза меньше высоты текста
        itemParam.s = "55" ' Текст компоненты
        doc.ksTextLine(itemParam) ' Компонента числителя

        itemFont.Init() ' Инициализация
        itemFont.SetBitVectorValue(DENOMINATOR, True) ' Знаменатель, утолщение
        itemParam.s = "77" ' Текст компоненты
        doc.ksTextLine(itemParam) ' Компонента знаменателя

        itemFont.Init() ' Инициализация
        itemFont.SetBitVectorValue(END_FRACTION, True) ' Конец дроби,
        itemFont.SetBitVectorValue(BOLD_OFF, True) ' снятие утолщения,
        itemFont.SetBitVectorValue(ITALIC_OFF, True) ' снятие наклона
        itemParam.s = "4444" ' Текст компоненты
        doc.ksTextLine(itemParam) ' Текст после дроби

        'UPGRADE_NOTE: Object itemFont may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        itemFont = Nothing

        ' Описание параграфа заканчивается функцией EndObj, возвращающей указатель на созданный объект
        p = doc.ksEndObj
      End If

      ' в параметрах текста задействованы два массива неопределенной длины :
      arr1 = par1.GetTextLineArr ' Массив по строкам

      arr2 = par2.GetTextItemArr ' Массив по компонентам строки

      If Not arr1 Is Nothing And Not arr2 Is Nothing Then ' Интерфейсы созданы
        doc.ksGetObjParam(p, par2, 0) ' Возьмем параметры 1 -ой строки ( индекс 0 )

        PrintPar1(par2, par3, arr2) ' Вывод параметров строки

        If Kompas.ksYesNo("Изменять параметры текста ?") Then
          ' У первой строки отключаем ITALIC и BOLD и меняем цвет
          arr2.ksGetArrayItem(0, par3)

          font = par3.GetItemFont ' Параметры Шрифта компоненты строки текста.
          If Not font Is Nothing Then ' Интерфейс получен
            font.SetBitVectorValue(BOLD_OFF, True) ' Снятие утолщения
            font.SetBitVectorValue(ITALIC_OFF, True) ' Снятие наклона
            font.color = RGB(0, 255, 0) ' Цвет шрифта - зеленый

            arr2.ksSetArrayItem(0, par3) ' Заменим первую компоненту
            doc.ksSetObjParam(p, par2, 0) ' Заменим у текста первую строку
            doc.ksGetObjParam(p, par2, 0) ' Возьмем параметры 1-ой строки ( индекс 0 )
            PrintPar1(par2, par3, arr2) ' Вывод параметров строки

            'UPGRADE_NOTE: Object font may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            font = Nothing
          End If
        End If

        'UPGRADE_NOTE: Object arr1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr1 = Nothing
        'UPGRADE_NOTE: Object arr2 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr2 = Nothing
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object par1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par1 = Nothing
      'UPGRADE_NOTE: Object par2 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par2 = Nothing
      'UPGRADE_NOTE: Object par3 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par3 = Nothing
      'UPGRADE_NOTE: Object itemParam may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      itemParam = Nothing
    End If
  End Sub

  ' Определить имя библиотеки

  Public Function GetLibraryName() As String
    GetLibraryName = "объекты" ' Имя библиотеки
  End Function

  ' Головная функция библиотеки - вызывается при выборе пункта меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Kompas6API5.Application)
    Kompas = kompas_ ' Интерфейс приложения КОМПАС
    Dim doc As Kompas6API5.Document2D ' Интерфейс ksDocument2D

    ' Получить интерфейс 2D документа
    If command_Renamed = 1 Then ' Для команды 1
      doc = Kompas.Document2D ' Возьмем пустой интерфейс 2D документа
    Else ' Для остальных команд
      doc = Kompas.ActiveDocument2D ' Возьмем интерфейс текущего 2D документа
    End If

    Select Case command_Renamed
      Case 1 ' Cоздать документ
        WorkDocument(doc)
      Case 2
        DrawView(doc) ' Виды
      Case 3
        DrawLayer(doc) ' Слои
      Case 4
        DrawGroup(doc) ' Группы
      Case 5
        WorkNameGroup(doc) ' Именная группа
      Case 6
        DrawLineSeg(doc) ' Отрезки
      Case 7
        DrawArc(doc) ' Дуги
      Case 8
        DrawLine(doc) ' Линии
      Case 9
        DrawCircle(doc) ' Окружности
      Case 10
        DrawPoint(doc) ' Точки
      Case 11
        DrawBezier(doc) ' Bezier-сплайны
      Case 12
        DrawHatch(doc) ' Штриховка
      Case 13
        DrawText(doc) ' Текст
    End Select
  End Sub

  ' Сформировать меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 3 '"ENDMENU"'
    ExternalMenuItem = ""
    command_Renamed = -1

    Select Case number
      Case 1 ' Команда 1 - Создать документ
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Создать документ"
        command_Renamed = 1
      Case 2 ' Команда 2 - Виды
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Виды"
        command_Renamed = 2
      Case 3 ' Команда 3 - Cлои
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Cлои"
        command_Renamed = 3
      Case 4 ' Команда 4 - Группы
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Группы"
        command_Renamed = 4
      Case 5 ' Команда 5 - Именная группа
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Именная группа"
        command_Renamed = 5
      Case 6 ' Команда 6 - Отрезки
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Отрезки"
        command_Renamed = 6
      Case 7 ' Команда 7 - Дуги
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Дуги"
        command_Renamed = 7
      Case 8 ' Команда 8 - Линии
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Линии"
        command_Renamed = 8
      Case 9 ' Команда 9 - Окружности
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Окружности"
        command_Renamed = 9
      Case 10 ' Команда 10 - Точки
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Точки"
        command_Renamed = 10
      Case 11 ' Команда 11 - Bezier-сплайны
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Bezier-сплайны"
        command_Renamed = 11
      Case 12 ' Команда 12 - Штриховка
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Штриховка"
        command_Renamed = 12
      Case 13 ' Команда 13 - Текст
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Текст"
        command_Renamed = 13
      Case 14 ' Завершение формирования меню
        itemType = 3 '"ENDMENU"'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

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