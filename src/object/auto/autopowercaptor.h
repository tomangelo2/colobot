/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2014, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsiteс.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */

// autopowercaptor.h

#pragma once


#include "object/auto/auto.h"



enum AutoPowerCaptorPhase
{
    APAP_WAIT       = 1,
    APAP_LIGHTNING  = 2,
    APAP_CHARGE     = 3,
};



class CAutoPowerCaptor : public CAuto
{
public:
    CAutoPowerCaptor(CObject* object);
    ~CAutoPowerCaptor();

    void        DeleteObject(bool bAll=false);

    void        Init();
    bool        EventProcess(const Event &event);
    Error       GetError();
    void        StartLightning();

    bool        CreateInterface(bool bSelect);

    bool        Write(CLevelParserLine* line);
    bool        Read(CLevelParserLine* line);

protected:
    void        ChargeObject(float rTime);

protected:
    AutoPowerCaptorPhase   m_phase;
    float           m_progress;
    float           m_speed;
    float           m_timeVirus;
    float           m_lastParticle;
    Math::Vector        m_pos;
    int             m_channelSound;
};
