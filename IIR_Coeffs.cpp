/*
    This file is part of the project OpenLD.

    OpenLD is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenLD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenLD.  If not, see <http://www.gnu.org/licenses/>.
*/

/* IIR coefficient layout:
    => b0, b1, b2, a1, a2
       ...
*/

double coeffs_hp[5 * 1] = {
    0.997493021323278,
    -0.997493021323278,
    0.000000000000000,
    -0.994986042646556,
    0.000000000000000,

};

double coeffs_lp[5 * 6] = {
    0.000012868584960, 0.000025737169919, 0.000012868584960, -0.583338368345278, 0.088669648124156,
    1.000000000000000, 2.000000000000000, 1.000000000000000, -0.602033202257445, 0.123559343987349,
    1.000000000000000, 2.000000000000000, 1.000000000000000, -0.641766234145572, 0.197712096818018,
    1.000000000000000, 2.000000000000000, 1.000000000000000, -0.707831996475455, 0.321008958693826,
    1.000000000000000, 2.000000000000000, 1.000000000000000, -0.809950298939133, 0.511589764694170,
    1.000000000000000, 2.000000000000000, 1.000000000000000, -0.965273753183481, 0.801466000260994,
};

double coeffs_hp_EOG[5 * 18] = {
    0.8591872536596467, -1.7183745073192933, 0.8591872536596467, -1.9737183887705767, 0.9738913944007946,
    1.0, -2.0, 1.0, -1.9739144994001183, 0.9740875222203484,
    1.0, -2.0, 1.0, -1.9743053443360243, 0.9744784014156376,
    1.0, -2.0, 1.0, -1.9748881780462064, 0.975061286213915,
    1.0, -2.0, 1.0, -1.9756589000550244, 0.9758320757801149,
    1.0, -2.0, 1.0, -1.9766120764310238, 0.976785335706473,
    1.0, -2.0, 1.0, -1.9777409685982019, 0.9779143268263194,
    1.0, -2.0, 1.0, -1.9790375695949205, 0.979211041476168,
    1.0, -2.0, 1.0, -1.9804926479186118, 0.9806662473442667,
    1.0, -2.0, 1.0, -1.982095799097537 , 0.9822695390468763,
    1.0, -2.0, 1.0, -1.9838355051213707, 0.9840093975640641,
    1.0, -2.0, 1.0, -1.9856992018387924, 0.985873257643203,
    1.0, -2.0, 1.0, -1.9876733543914931, 0.9878475832395903,
    1.0, -2.0, 1.0, -1.9897435406992383, 0.9899179510088292,
    1.0, -2.0, 1.0, -1.9918945429396282, 0.9920691417946065,
    1.0, -2.0, 1.0, -1.994110446879044 , 0.9942852399683465,
    1.0, -2.0, 1.0, -1.9963747488087777, 0.9965497403747143,
    1.0, -2.0, 1.0, -1.9986704697237774, 0.9988456625203688
};