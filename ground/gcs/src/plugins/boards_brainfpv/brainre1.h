/**
 ******************************************************************************
 * @file       brainre1.h
 * @author     BrainFPV 2015
 *
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup Boards_BrainFPVPlugin BrainFPV boards support Plugin
 * @{
 * @brief Plugin to support boards by BrainFPV
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef BRAINRE1_H
#define BRAINRE1_H

#include <coreplugin/iboardtype.h>

class IBoardType;

class BrainRE1 : public Core::IBoardType
{
public:
    BrainRE1();
    virtual ~BrainRE1();

    virtual QString shortName();
    virtual QString boardDescription();
    virtual bool queryCapabilities(BoardCapabilities capability);
    virtual QStringList getSupportedProtocols();
    virtual QPixmap getBoardPicture();
    virtual QString getHwUAVO();

    //! Determine if this board supports configuring the receiver
    virtual bool isInputConfigurationSupported(InputType type);

    /**
     * Configure the board to use an receiver input type on a port number
     * @param type the type of receiver to use
     * @param port_num which input port to configure (board specific numbering)
     */
    virtual bool setInputType(enum InputType type);

    /**
     * @brief getInputOnPort get the current input type
     * @param port_num which input port to query (board specific numbering)
     * @return the currently selected input type
     */
    virtual enum InputType getInputType();

    /**
     * @brief getConnectionDiagram get the connection diagram for this board
     * @return a string with the name of the resource for this board diagram
     */
    virtual QString getConnectionDiagram() { return ":/brainfpv/images/brainre1-connection-diagram.svg"; }

    virtual int queryMaxGyroRate();
    QWidget * getBoardConfiguration(QWidget *parent, bool connected);
    virtual QStringList getAdcNames();
};


#endif // BRAINRE1_H
