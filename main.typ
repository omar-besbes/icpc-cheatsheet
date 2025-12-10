#set document(
  author: ("Omar Besbes", "Hatem Gharsallah", "Mohamed Yousfi"),
  title: "ICPC cheatsheet",
  date: datetime.today(),
  keywords: ("ICPC", "ACPC", "TCPC", "competitive programming"),
  description: "ICPC algorithms and data structures reference",
)
#set page(
  paper: "presentation-16-9",
  margin: (
    top: 0.6in,
    bottom: 0.6in,
    left: 0.3in,
    right: 0.3in,
  ),
  numbering: "1",
)
#set text(size: 10pt)
#set par(justify: true)
#set heading(numbering: "1.1")

#show raw: set block(spacing: 0pt)
#show raw: set text(size: 7pt, top-edge: "x-height")

#show outline.entry.where(level: 1): set text(weight: "bold")

//#show math.equation: set align(center)

#include "src/content.typ"
