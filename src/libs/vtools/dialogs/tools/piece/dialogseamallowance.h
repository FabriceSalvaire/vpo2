/************************************************************************
 **
 **  @file   dialogseamallowance.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   3 11, 2016
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2016 Valentina project
 **  <https://bitbucket.org/dismine/valentina> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef DIALOGSEAMALLOWANCE_H
#define DIALOGSEAMALLOWANCE_H

#include "../dialogtool.h"
#include "../vpatterndb/vpiece.h"
#include "../vpatterndb/floatItemData/vpatternlabeldata.h"
#include "../vpatterndb/floatItemData/vpiecelabeldata.h"
#include "../vpatterndb/floatItemData/vgrainlinedata.h"

namespace Ui
{
    class DialogSeamAllowance;
    class TabPaths;
    class TabLabels;
    class TabGrainline;
    class TabPins;
    class TabPassmarks;
}

class VisPiecePins;
class FancyTabBar;

class DialogSeamAllowance : public DialogTool
{
    Q_OBJECT

public:
    DialogSeamAllowance(const VContainer *data, const quint32 &toolId, QWidget *parent = nullptr);
    virtual ~DialogSeamAllowance();

    void EnableApply(bool enable);

    VPiece GetPiece() const;
    void   SetPiece(const VPiece &piece);

    QString GetFormulaSAWidth() const;

public slots:
    virtual void ChosenObject(quint32 id, const SceneObject &type) Q_DECL_OVERRIDE;
    virtual void ShowDialog(bool click) Q_DECL_OVERRIDE;

protected:
    /** @brief SaveData Put dialog data in local variables */
    virtual void SaveData() Q_DECL_OVERRIDE;
    virtual void CheckState() Q_DECL_FINAL;
    virtual void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
    virtual void showEvent( QShowEvent *event ) Q_DECL_OVERRIDE;
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private slots:
    void NameDetailChanged();
    void ShowMainPathContextMenu(const QPoint &pos);
    void ShowCustomSAContextMenu(const QPoint &pos);
    void ShowInternalPathsContextMenu(const QPoint &pos);
    void ShowPinsContextMenu(const QPoint &pos);

    void ListChanged();
    void EnableSeamAllowance(bool enable);
    void NodeChanged(int index);
    void PassmarkChanged(int index);
    void CSAStartPointChanged(int index);
    void CSAEndPointChanged(int index);
    void CSAIncludeTypeChanged(int index);
    void NodeAngleChanged(int index);
    void ReturnDefBefore();
    void ReturnDefAfter();
    void CustomSAChanged(int row);
    void PathDialogClosed(int result);
    void FancyTabChanged(int index);
    void TabChanged(int index);
    void PassmarkLineTypeChanged(int id);
    void PassmarkAngleTypeChanged(int id);
    void PassmarkShowSecondChanged(int state);

    void UpdateGrainlineValues();
    void UpdateDetailLabelValues();
    void UpdatePatternLabelValues();

    void EditGrainlineFormula();
    void EditDLFormula();
    void EditPLFormula();

    void DeployGrainlineRotation();
    void DeployGrainlineLength();

    void DeployDLWidth();
    void DeployDLHeight();
    void DeployDLAngle();

    void DeployPLWidth();
    void DeployPLHeight();
    void DeployPLAngle();

    void ResetGrainlineWarning();
    void ResetLabelsWarning();

    void EnabledGrainline();
    void EnabledDetailLabel();
    void EnabledPatternLabel();

    void EvalWidth();
    void EvalWidthBefore();
    void EvalWidthAfter();

    void FXWidth();
    void FXWidthBefore();
    void FXWidthAfter();

    void WidthChanged();
    void WidthBeforeChanged();
    void WidthAfterChanged();

    void DeployWidthFormulaTextEdit();
    void DeployWidthBeforeFormulaTextEdit();
    void DeployWidthAfterFormulaTextEdit();

    void GrainlinePinPointChanged();
    void DetailPinPointChanged();
    void PatternPinPointChanged();

    void EditLabel();

private:
    Q_DISABLE_COPY(DialogSeamAllowance)

    Ui::DialogSeamAllowance *ui;
    Ui::TabPaths            *uiTabPaths;
    Ui::TabLabels           *uiTabLabels;
    Ui::TabGrainline        *uiTabGrainline;
    Ui::TabPins             *uiTabPins;
    Ui::TabPassmarks        *uiTabPassmarks;

    QWidget *m_tabPaths;
    QWidget *m_tabLabels;
    QWidget *m_tabGrainline;
    QWidget *m_tabPins;
    QWidget *m_tabPassmarks;

    FancyTabBar* m_ftb;

    bool   applyAllowed;
    bool   flagGPin;
    bool   flagDPin;
    bool   flagPPin;
    bool   flagGFormulas;
    bool   flagDLAngle;
    bool   flagDLFormulas;
    bool   flagPLAngle;
    bool   flagPLFormulas;
    bool   m_bAddMode;
    qreal  m_mx;
    qreal  m_my;

    QPointer<DialogTool>   m_dialog;
    QPointer<VisPiecePins> m_visPins;

    VPieceLabelData   m_oldData;
    VPatternLabelData m_oldGeom;
    VGrainlineData    m_oldGrainline;
    int                  m_iRotBaseHeight;
    int                  m_iLenBaseHeight;
    int                  m_DLWidthBaseHeight;
    int                  m_DLHeightBaseHeight;
    int                  m_DLAngleBaseHeight;
    int                  m_PLWidthBaseHeight;
    int                  m_PLHeightBaseHeight;
    int                  m_PLAngleBaseHeight;
    int                  m_formulaBaseWidth;
    int                  m_formulaBaseWidthBefore;
    int                  m_formulaBaseWidthAfter;

    QTimer *m_timerWidth;
    QTimer *m_timerWidthBefore;
    QTimer *m_timerWidthAfter;
    qreal   m_saWidth;

    QVector<VLabelTemplateLine> m_templateLines;

    VPiece CreatePiece() const;

    void    NewMainPathItem(const VPieceNode &node);
    void    NewCustomSA(const CustomSARecord &record);
    void    NewInternalPath(quint32 path);
    void    NewPin(quint32 pinPoint);
    QString GetPathName(quint32 path, bool reverse = false) const;
    bool    MainPathIsValid() const;
    void    ValidObjects(bool value);
    bool    MainPathIsClockwise() const;
    void    UpdateCurrentCustomSARecord();
    void    UpdateCurrentInternalPathRecord();

    QListWidgetItem *GetItemById(quint32 id);

    quint32 GetLastId() const;

    void SetCurrentSABefore(const QString &formula);
    void SetCurrentSAAfter(const QString &formula);

    void UpdateNodeSABefore(const QString &formula);
    void UpdateNodeSAAfter(const QString &formula);

    void InitFancyTabBar();
    void InitMainPathTab();
    void InitSeamAllowanceTab();
    void InitNodesList();
    void InitPassmarksList();
    void InitCSAPoint(QComboBox *box);
    void InitPinPoint(QComboBox *box);
    void InitSAIncludeType();
    void InitInternalPathsTab();
    void InitPatternPieceDataTab();
    void InitLabelsTab();
    void InitGrainlineTab();
    void InitPinsTab();
    void InitPassmarksTab();
    void InitAllPinComboboxes();

    void SetFormulaSAWidth(const QString &formula);

    void SetGrainlineAngle(QString angleFormula);
    void SetGrainlineLength(QString lengthFormula);

    void SetDLWidth(QString widthFormula);
    void SetDLHeight(QString heightFormula);
    void SetDLAngle(QString angleFormula);

    void SetPLWidth(QString widthFormula);
    void SetPLHeight(QString heightFormula);
    void SetPLAngle(QString angleFormula);

    void ShowPins();
};

#endif // DIALOGSEAMALLOWANCE_H
