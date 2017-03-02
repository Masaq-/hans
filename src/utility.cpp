/*
 *  Hans - IP over ICMP
 *  Copyright (C) 2009 Friedrich Schöller <hans@schoeller.se>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

string Utility::formatIp(struct in6_addr ip)
{
    if (ip.s6_addr32[0] == 0 && ip.s6_addr32[1] == 0 && ip.s6_addr[8] == 0 && ip.s6_addr[9] == 0 && ip.s6_addr[10] == 0xff && ip.s6_addr[11] == 0xff)
        return formatIp(ntohl(ip.s6_addr32[3]));
    char buffer[40];
    sprintf(buffer, "%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x", ip.s6_addr[0],ip.s6_addr[1],ip.s6_addr[2],ip.s6_addr[3],ip.s6_addr[4],ip.s6_addr[5],ip.s6_addr[6],ip.s6_addr[7],ip.s6_addr[8],ip.s6_addr[9],ip.s6_addr[10],ip.s6_addr[11],ip.s6_addr[12],ip.s6_addr[13],ip.s6_addr[14],ip.s6_addr[15]);
    return buffer;
}

string Utility::formatIp(uint32_t ip)
{
    char buffer[16];
    sprintf(buffer, "%d.%d.%d.%d", (ip >> 24) & 0xff, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
    return buffer;
}

int Utility::rand()
{
    static bool init = false;
    if (!init)
    {
        init = true;
        srand(time(NULL));
    }
    return ::rand();
}
