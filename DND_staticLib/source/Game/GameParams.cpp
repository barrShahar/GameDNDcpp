#include "pch.h"
#include "GameParams.h"

experis::AttackPlayerResponse::AttackPlayerResponse(bool a_isValid)
    : m_isValid { a_isValid }
{

}

experis::Number experis::AttackPlayerResponse::GetOtherPlayerLifePoints()
{
    return m_DamageToOtherPlayer;
}

experis::Number experis::AttackPlayerResponse::GetDamageToThisPlayer() const
{
    return m_DamageToPlayer;
}
